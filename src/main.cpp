#include <iostream>
#include <string>
#include <vector>

#include "fen.hpp"
#include "move.hpp"

int main(void) {
  std::string fen_str;

  move::Move move = {{0, 0}, {0, 0}, 0};
  std::vector<move::Move> vec = {}; 
  
  std::cin >> fen_str;
  fen::Fen f(fen_str);

  

  return 0;
}
