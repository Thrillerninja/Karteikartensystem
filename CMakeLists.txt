cmake_minimum_required(VERSION 3.3)
project(Karteikartensystem)

#set(CMAKE_CXX_COMPILER "")
set(CMAKE_CXX_STANDARD 14)

include_directories(src)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)