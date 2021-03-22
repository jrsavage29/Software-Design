cmake_minimum_required(VERSION 3.5)
project(basic_type CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Widgets Test  REQUIRED)
find_package(Threads)



add_executable(cpp11_prodcon cpp11_prodcon.cpp)
TARGET_LINK_LIBRARIES(cpp11_prodcon Qt5::Core Qt5::Widgets ${CMAKE_THREAD_LIBS_INIT})