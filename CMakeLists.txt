cmake_minimum_required(VERSION 3.24)
project(TicTakToe)

set(CMAKE_CXX_STANDARD 17)

#add_executable(TicTakToe src/app/main.cpp src/libPlayer/PlayerType.cpp src/libBoard/Board.cpp src/libPlayer/Player.cpp)
add_subdirectory(src)
