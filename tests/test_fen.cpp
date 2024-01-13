#include <string>
#include <gtest/gtest.h>

#include "fen.hpp"

using namespace fen;
using namespace std;

class InvalidFenParametrizedTestFixture: public ::testing::TestWithParam<string> {};

TEST_P(InvalidFenParametrizedTestFixture, InvalidFen) {
  ASSERT_THROW(Fen f(GetParam()), InvalidFenException);
}

INSTANTIATE_TEST_SUITE_P(
  InvalidFen,
  InvalidFenParametrizedTestFixture,
  ::testing::Values(
    "rnbqkbnr/8/8/8/8/8/8/RNBQKBNR w KQkq - 0",   // missing ply
    "rnbqkbnr/8/8/8/8/8/8/RNBQKBNR KQkq - 0 1"   // missing tun
  )
);

INSTANTIATE_TEST_SUITE_P(
  InvalidBoard,
  InvalidFenParametrizedTestFixture,
  ::testing::Values(
    "8/8/8/8/8/8/8/8/8 w KQkq - 0 1",        // too many rows
    "8/8/8/8/8/8/8 w KQkq - 0 1",            // too few rows
    "8/8/8/8/9/8/8/8 w KQkq - 0 1",          // numeric row too large
    "8/8/8/8/7/8/8/8 w KQkq - 0 1",          // numeric row too small
    "8/8/8/8/ppppppppp/8/8/8 w KQkq - 0 1",  // alphabetic row too large
    "8/8/8/8/ppppppp/8/8/8 w KQkq - 0 1",    // alphabetic row too small
    "8/8/8/8/4p4/8/8/8 w KQkq - 0 1",        // mixed row too large
    "8/8/8/8/4p2/8/8/8 w KQkq - 0 1",        // mixed row too small
    "8/8/8/8//8/8/8 w KQkq - 0 1"            // absent token
  )
);

INSTANTIATE_TEST_SUITE_P(
  InvalidTurn,
  InvalidFenParametrizedTestFixture,
  ::testing::Values(
    "8/8/8/8/8/8/8/8 - KQkq - 0 1",  // no turn
    "8/8/8/8/8/8/8/8 W KQkq - 0 1",  // capitalised W
    "8/8/8/8/8/8/8/8 B KQkq - 0 1"   // capitalised B
  )
);

INSTANTIATE_TEST_SUITE_P(
  InvalidCastlingRights,
  InvalidFenParametrizedTestFixture,
  ::testing::Values(
    "8/8/8/8/8/8/8/8 w KQ? - 0 1",  // invalid character
    "8/8/8/8/8/8/8/8 w KKQ - 0 1"   // repetition
  )
);

INSTANTIATE_TEST_SUITE_P(
  InvalidEnPassent,
  InvalidFenParametrizedTestFixture,
  ::testing::Values(
    "8/8/8/8/8/8/8/8 w - ? 0 1",   // invalid character
    "8/8/8/8/8/8/8/8 w - i3 0 1",  // invalid file
    "8/8/8/8/8/8/8/8 w - a4 0 1"   // invalid rank    
  )
);

INSTANTIATE_TEST_SUITE_P(
  InvalidMoveCount,
  InvalidFenParametrizedTestFixture,
  ::testing::Values(
    "8/8/8/8/8/8/8/8 w - - - 1",   // absent
    "8/8/8/8/8/8/8/8 w - - 1? 1"  // invalid character
  )
);

INSTANTIATE_TEST_SUITE_P(
  InvalidPly,
  InvalidFenParametrizedTestFixture,
  ::testing::Values(
    "8/8/8/8/8/8/8/8 w - - 0 -",   // absent
    "8/8/8/8/8/8/8/8 w - - 0 1?"  // invalid character
  )
);

class ValidFenParametrizedTestFixture: public ::testing::TestWithParam<string> {};

TEST_P(ValidFenParametrizedTestFixture, ValidFen) {
  ASSERT_NO_THROW(Fen f(GetParam()));
}

INSTANTIATE_TEST_SUITE_P(
  ValidBoard,
  ValidFenParametrizedTestFixture,
  ::testing::Values(
    "8/8/8/8/8/8/8/8 w KQkq - 0 1",               // empy board
    "k7/8/8/8/8/8/8/7K w - - 0 1",                // naked kings
    "rnbqkbnr/8/8/8/8/8/8/RNBQKBNR w KQkq - 0 1"  // starting position
  ));

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


