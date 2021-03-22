cmake_minimum_required(VERSION 3.5)
project(vtqulator CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Widgets Test REQUIRED)

# optional strict mode
if(UNIX AND STRICT)
  message("-- Enabling strict compilation mode")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

add_executable(vtqulator vtqulator_main.cpp vtqulator_gui.cpp vtqulator_gui.h output_window.cpp output_window.h Interpreter.cpp Interpreter.h)
target_link_libraries(vtqulator Qt5::Widgets)

add_executable(test_vtqulator test_vtqulator.cpp vtqulator_gui.cpp vtqulator_gui.h output_window.cpp output_window.h Interpreter.cpp Interpreter.h)
target_link_libraries(test_vtqulator Qt5::Widgets Qt5::Test)

enable_testing()
add_test(test_vtqulator test_vtqulator)
