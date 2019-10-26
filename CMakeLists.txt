cmake_minimum_required(VERSION 3.15)
project(C-Lab C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
add_executable(C-Lab "demo/2019-10-9 Queue/GameQueueEvent.c" "demo/2019-10-12 String/KMPTest.c" "demo/2019-10-12 String/String.h" "demo/2019-10-12 String/StringTest.c" "demo/2019-10-17 Array/ArrayBase.h" "demo/2019-10-17 Array/MatrixStorage.c" "demo/2019-10-17 Array/MatrixBase.h" "demo/2019-10-17 Array/ArrayTest.c" "demo/2019-10-25 Tree/TreeBase.h" "demo/2019-10-25 Tree/TreeTest.c" "demo/2019-10-25 Tree/BinaryTree.h")