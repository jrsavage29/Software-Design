cmake_minimum_required(VERSION 3.5)
project(Ex10 CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)

add_executable(ex10 main.cpp complex_widget.hpp complex_widget.cpp)
set(TARGET ex10 PROPERTY CXX_STANDARD 11)
target_link_libraries(ex10 Qt5::Widgets)
