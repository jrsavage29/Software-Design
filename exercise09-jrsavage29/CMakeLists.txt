cmake_minimum_required(VERSION 3.5)
project(QtPoly CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)

add_executable(poly buttons.cpp poly.cpp)

target_link_libraries(poly Qt5::Widgets)
