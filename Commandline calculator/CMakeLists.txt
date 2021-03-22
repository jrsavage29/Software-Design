cmake_minimum_required(VERSION 3.5)
project(Project2-Desk-Calculator CXX)

# optional strict mode
if(UNIX AND STRICT)
  message("-- Enabling strict compilation mode")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

add_executable(vtcalc vtcalc.cpp Interpreter.cpp Interpreter.h)
add_executable(unit_test unit_test.cpp catch.hpp Interpreter.cpp Interpreter.h)
set_property(TARGET vtcalc PROPERTY CXX_STANDARD 11)
set_property(TARGET unit_test PROPERTY CXX_STANDARD 11)

