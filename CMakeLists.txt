cmake_minimum_required(VERSION 3.15)
project(C-Lab C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
add_executable(C-Lab "demo/2019-12-4 Searching/SearchingTest.c" "demo/2019-12-4 Searching/SimpleBinarySearchTree.c")