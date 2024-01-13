#include <string>
#include <unordered_set>

#include <gtest/gtest.h>

#include "board.hpp"
#include "fen.hpp"
#include "move.hpp"

using namespace board;
using namespace std;

class BoardStringParametrizedTestFixture:
  public ::testing::TestWithParam<pair<string, string>> {};

TEST_P(BoardStringParametrizedTestFixture, BoardString) {
  auto params = GetParam();
  fen::Fen fen(params.first);
  Board board(fen);
  ASSERT_EQ(board.boardString(), params.second);
}

INSTANTIATE_TEST_SUITE_P(
  BoardString,
  BoardStringParametrizedTestFixture,
  ::testing::Values(
    pair<string, string>( // starting position
      {"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1",
       "rnbqkbnr\n"
       "pppppppp\n"
       "........\n"
       "........\n"
       "........\n"
       "........\n"
       "PPPPPPPP\n"
       "RNBQKBNR *\n"}
    ),
    pair<string, string>( // position after 1.e4
      {"rnbqkbnr/pppppppp/8/8/4P3/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1",
       "rnbqkbnr *\n"
       "........\n"
       "........\n"
       "........\n"
       "....P...\n"
       "........\n"
       "PPPP.PPP\n"
       "RNBQKBNR\n"}
    )
  )  
);

class MovesListParametrizedTestFixture:
  public ::testing::TestWithParam<pair<string, vector<string>>> {};

TEST_P(MovesListParametrizedTestFixture, MovesList) {
  auto params = GetParam();
  fen::Fen fen(params.first);
  Board board(fen);
  ASSERT_EQ(board.movesList(), params.second);
}

INSTANTIATE_TEST_SUITE_P(
  MovesList,
  MovesListParametrizedTestFixture,
  ::testing::Values(
    pair<string, vector<string>>( // starting position
      {"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1",
       {"a2a3",
	"a2a4",
	"b1a3",
	"b1c3",	
	"b2b3",
	"b2b4",
	"c2c3",
	"c2c4",
	"d2d3",
	"d2d4",
	"e2e3",
	"e2e4",
	"f2f3",
	"f2f4",
	"g1f3",
	"g1h3",
	"g2g3",
	"g2g4",
	"h2h3",
	"h2h4"}
      }
    ),
    pair<string, vector<string>>( // white B+K vs black K
      {"k7/8/8/4B3/8/8/8/7K w - - 0 1",
       {"e5a1",
	"e5b2",
	"e5b8",	
	"e5c3",
	"e5c7",	
	"e5d4",
	"e5d6",	
	"e5f4",
	"e5f6",	
	"e5g3",
	"e5g7",	
	"e5h2",
	"e5h8",
	"h1g1",
	"h1g2",
	"h1h2"}
      }
    ),
    pair<string, vector<string>>( // black K+N vs white K
      {"k7/8/8/4n3/8/8/8/7K b - - 0 1",
       {"a8a7",
	"a8b7",
	"a8b8",
	"e5c4",
	"e5c6",
	"e5d3",	
	"e5d7",
	"e5f3",	
	"e5f7",
	"e5g4",	
	"e5g6"}
      }
    ),
    pair<string, vector<string>>( // white K+R vs black K
      {"k7/8/8/4R3/8/8/8/7K w - - 0 1",
       {"e5a5",
	"e5b5",
	"e5c5",	
	"e5d5",
	"e5e1",	
	"e5e2",
	"e5e3",	
	"e5e4",
	"e5e6",	
	"e5e7",
	"e5e8",	
	"e5f5",
	"e5g5",
       	"e5h5",
	"h1g1",
	"h1g2",
	"h1h2"}
      }
    ),
    pair<string, vector<string>>( // black K+Q vs white K
      {"k7/8/8/4q3/8/8/8/7K b - - 0 1",
       {"a8a7",
	"a8b7",
	"a8b8",
	"e5a1",
	"e5a5",
	"e5b2",	
	"e5b5",
	"e5b8",
	"e5c3",		
	"e5c5",
	"e5c7",
	"e5d4",	
	"e5d5",
	"e5d6",	
	"e5e1",	
	"e5e2",
	"e5e3",	
	"e5e4",
	"e5e6",	
	"e5e7",
	"e5e8",
	"e5f4",	
	"e5f5",
	"e5f6",
	"e5g3",	
	"e5g5",
	"e5g7",
       	"e5h2",	
       	"e5h5",
       	"e5h8"}
      }
    ),
    pair<string, vector<string>>( // white pawn captures
      {"k7/8/3n4/4Pp2/8/8/8/7K w - f6 0 1",
       {"e5d6",
	"e5e6",
	"e5f6",	
	"h1g1",
	"h1g2",
	"h1h2"}
      }
    ),
    pair<string, vector<string>>( // black pawn captures
      {"k7/8/8/8/4pP2/3B4/8/7K b - - 0 1",
       {"a8a7",
	"a8b7",
	"a8b8",
	"e4d3",
	"e4e3",
	"e4f3"}
      }
    ),
    pair<string, vector<string>>( // white castling rights all
      {"k7/8/8/8/8/8/8/R3K2R w KQ - 0 1",
       {"e1c1",
	"e1d1",
	"e1d2",
	"e1e2",
	"e1f1",
	"e1f2",	
	"e1g1"}
      }
    ),    
    pair<string, vector<string>>( // white castling rights kingside only
      {"k7/8/8/8/8/8/8/R3K2R w K - 0 1",
	{"e1d1",
	"e1d2",
	"e1e2",
	"e1f1",
	"e1f2",	
	"e1g1"}
      }
    ),    
    pair<string, vector<string>>( // white castling rights queenside only
      {"k7/8/8/8/8/8/8/R3K2R w Q - 0 1",
       {"e1c1",
	"e1d1",
	"e1d2",
	"e1e2",
	"e1f1",
	"e1f2"}
      }
    ),    
    pair<string, vector<string>>( // white castling rights none
      {"k7/8/8/8/8/8/8/R3K2R w - - 0 1",
       {"e1d1",
	"e1d2",
	"e1e2",
	"e1f1",
	"e1f2"}
      }
    ),    
    pair<string, vector<string>>( // black castling rights all
      {"r3k2r/8/8/8/8/8/8/7K b kq - 0 1",
       {"e8c8",
	"e8d8",
	"e8d7",
	"e8e7",
	"e8f8",
	"e8f7",	
	"e8g8"}
      }
    ),    
    pair<string, vector<string>>( // black castling rights kingside only
      {"r3k2r/8/8/8/8/8/8/7K b k - 0 1",      
       {"e8d8",
	"e8d7",
	"e8e7",
	"e8f8",
	"e8f7",	
	"e8g8"}
      }
    ),    
    pair<string, vector<string>>( // black castling rights queenside only
      {"r3k2r/8/8/8/8/8/8/7K b q - 0 1",      
       {"e8c8",
	"e8d8",
	"e8d7",
	"e8e7",
	"e8f8",
	"e8f7"}
      }
    ),    
    pair<string, vector<string>>( // black castling rights none
      {"r3k2r/8/8/8/8/8/8/7K b - - 0 1",      
       {"e8d8",
	"e8d7",
	"e8e7",
	"e8f8",
	"e8f7"}
      }
    )
  )
);

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


