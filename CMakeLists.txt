cmake_minimum_required(VERSION 3.10)

project(Chessage VERSION 1.0)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_14)

add_subdirectory(src)
add_subdirectory(tests)
