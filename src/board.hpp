#pragma once

#include <string>
#include <vector>
#include "fen.hpp"
#include "move.hpp"

namespace board {

  class InvalidBoardException: public std::exception {
  public:
    const char* what();
  };

  class Board {
  public:
    Board(fen::Fen);

    char grid[12][12];

    std::string boardString(void);
    std::vector<std::string> movesList(void);
  };
}
