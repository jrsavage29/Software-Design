cmake_minimum_required(VERSION 3.5)
project(Project1-GENQUOTE CXX)

# optional strict mode
if(UNIX AND STRICT)
  message("-- Enabling strict compilation mode")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

add_executable(genquote genquote.cpp)
set_property(TARGET genquote PROPERTY CXX_STANDARD 11)
