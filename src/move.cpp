#include "move.hpp"

#include <string>

using namespace std;

namespace move {

  Move::Move(string uci) {
    source = {0, 0};
    target = {0, 0};
    promotion = 0;
  }

  Move::Move(Square s, Square t, char p) {
    source = s;
    target = t;
    promotion = p;
  }

  string Move::to_uci(void) {
    return "";
  }
  
}
