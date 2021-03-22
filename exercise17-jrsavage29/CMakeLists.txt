cmake_minimum_required(VERSION 3.2)
project(Ex17 CXX)

# require a C++11 compiler
# use it for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 REQUIRED Core Concurrent)

ADD_EXECUTABLE(qt_concurrent qt_concurrent.cpp)
TARGET_LINK_LIBRARIES(qt_concurrent Qt5::Core Qt5::Concurrent)

