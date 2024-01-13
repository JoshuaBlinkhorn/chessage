#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <map>

#include "fen.hpp"

using namespace std;

namespace fen {

  const char* InvalidFenException::what() {
      return "Invalid FEN";
  }
  
  Fen::Fen(string str) {
    if (not isValidFen(str)) {
      throw InvalidFenException();
    }
    fen_str = str;
  }

  bool Fen::isValidFen(string str) {
    vector<string> tokens;
    stringstream stream(str);
    string token;

    while(getline(stream, token, ' ')) {
      tokens.push_back(token);
    }

    if(tokens.size() != 6) {
      return false;
    }

    if (isValidBoard(tokens[0]) &&
	isValidTurn(tokens[1]) &&
	isValidCastlingRights(tokens[2]) &&
	isValidEnPassent(tokens[3]) &&
	isValidInteger(tokens[4]) &&
	isValidInteger(tokens[5])) {
      return true;
    } else {
      return false;
    }
  }

  bool Fen::isValidBoard(string str) {
    vector<string> board;
    stringstream stream(str);
    string row;

    while(getline(stream, row, '/')) {
      board.emplace_back(row);
    }

    if(board.size() != 8) {
      return false;
    }
    
    for (string row: board) {
      if(not isValidRow(row)) {
	  return false;
      }
    }
    
    return true;
  }

  bool Fen::isValidRow(string str) {
    int num_squares = 0;
    string pieces = "pnbrqkPNBRQK";
    
    for (auto &c: str) {
      if (pieces.find(c) == string::npos) {
	if (isdigit(c)) {
	  num_squares += (c - '0');
	} else {
	  return false;
	}
      } else {
	num_squares++;
      }
    }
    return num_squares == 8;
  }
  
  bool Fen::isValidTurn(string str) {
    return str == "w" || str == "b";
  }
  
  bool Fen::isValidCastlingRights(string str) {
    bool right;

    if (str == "-") {
      return true;
    }

    map<char, bool> rights = {
      {'K', false},
      {'Q', false},
      {'k', false},
      {'q', false},      
    };

    for (auto &c: str) {      
      try {
	right = rights.at(c);
	if (right == true) {
	  return false;
	} else {
	  rights[c] = true;
	}
      }
      catch(exception& e) {
	return false;
      }
    }

    return true;
  }
  
  bool Fen::isValidEnPassent(string str) {
    string files = "abcdefgh";
    string ranks = "36";
      
    if (str == "-") {
      return true;
    }

    return (
      str.length() == 2 &&
      files.find(str[0]) != string::npos &&
      ranks.find(str[1]) != string::npos
    );
  }
  
  bool Fen::isValidInteger(string str) {
    for (auto &c: str) {
      if (not isdigit(c)) {
	return false;
      }
    }
    return true;
  }  
}
