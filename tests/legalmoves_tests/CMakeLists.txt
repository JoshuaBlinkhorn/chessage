add_executable(legalmoves_tests main.cpp test_fen.cpp test_board.cpp)
target_include_directories(
	legalmoves_tests
	INTERFACE ${GTEST_INCLUDE_DIRS}
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
	)
target_link_libraries(
	legalmoves_tests
	PUBLIC compiler_flags
	PUBLIC legalmoves
	PUBLIC ${GTEST_LIBRARIES}
	)
