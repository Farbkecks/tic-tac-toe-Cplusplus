add_library(Board Board.cpp)

target_include_directories(Board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Board Player)