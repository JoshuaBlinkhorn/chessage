#pragma once

#include <iostream>
#include <string>

namespace fen {

  class InvalidFenException: public std::exception {
  public:
    const char* what();
  };
  
  class Fen {
  public:    
    Fen(std::string fen_str);
    std::string fen_str;

  private:
    static bool isValidFen(std::string str);
    static bool isValidBoard(std::string str);
    static bool isValidRow(std::string str);    
    static bool isValidTurn(std::string str);
    static bool isValidCastlingRights(std::string str);
    static bool isValidEnPassent(std::string str);
    static bool isValidInteger(std::string str);

    void parseFen(std::string fen_str);
  };
}
