add_subdirectory(legalmoves)

add_executable(chessage main.cpp)

target_link_libraries(
	chessage
	PUBLIC legalmoves	
	PUBLIC compiler_flags
	)
