cmake_minimum_required(VERSION 3.5)
project(Exercise7 CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_treap treap_bst treap_bst.txx catch.hpp test_treap)
add_executable(compress treap_bst treap_bst.txx compress)

enable_testing(unittest test_treap)