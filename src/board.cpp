#include <vector>
#include <string>

#include "board.hpp"
#include "move.hpp"

using namespace std;

namespace board {

  const char* InvalidBoardException::what() {
    return "Invalid chess position";
  }

  Board::Board(fen::Fen fen) {}

  string Board::boardString(void) {
    return "";
  }

  vector<string> Board::movesList(void) {
    return {};
  }
}
