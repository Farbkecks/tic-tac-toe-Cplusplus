add_library(Player PlayerType.cpp Player.cpp PlayerType.h Player.h)

target_include_directories(Player PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
