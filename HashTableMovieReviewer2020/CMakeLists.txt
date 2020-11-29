cmake_minimum_required(VERSION 3.15)
project(HashTableMovieReviewer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(TestHashTable hashmain.cpp shphashtable.cpp shphashtable.h)
add_executable(MovieReviews moviemain.cpp shphashtable.cpp shphashtable.h WordEntry.cpp WordEntry.h)
