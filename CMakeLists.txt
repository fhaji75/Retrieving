cmake_minimum_required(VERSION 3.7)
project(Retrieving)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp include/InvertedIndex.h src/InvertedIndex.cpp)
add_executable(Retrieving ${SOURCE_FILES})