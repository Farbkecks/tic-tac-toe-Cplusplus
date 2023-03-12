cmake_minimum_required(VERSION 3.24)
project(TicTakToe)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTakToe main.cpp PlayerType.cpp Board.cpp Player.cpp)
