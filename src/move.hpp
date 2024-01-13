#pragma once

#include <string>

namespace move {

  struct Square {
    short int file;
    short int rank;
  };

  class Move {
  public:
    Move(std::string uci);
    Move(Square source, Square target, char promotion);

    std::string to_uci(void);

    Square source;
    Square target;
    char promotion;    
  };

}
