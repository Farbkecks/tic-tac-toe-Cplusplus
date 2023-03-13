add_library(MinMax MinMax.cpp MinMax.h)

target_include_directories(MinMax PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MinMax Board Player)