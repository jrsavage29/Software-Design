cmake_minimum_required(VERSION 3.5)
project(Project4-VTmath CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Widgets Test REQUIRED)
find_package(Threads REQUIRED)

# optional strict mode
if(UNIX AND STRICT)
  message("-- Enabling strict compilation mode")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

add_executable(vtqulator vtqulator_main.cpp vtqulator_gui.cpp vtqulator_gui.h output_window.cpp output_window.h Interpreter.cpp Interpreter.h VTmath.h VTmath.cpp)
target_link_libraries(vtqulator Qt5::Widgets)
add_executable(test_vtqulator test_vtqulator.cpp vtqulator_gui.cpp vtqulator_gui.h output_window.cpp output_window.h Interpreter.cpp Interpreter.h VTmath.h VTmath.cpp)
target_link_libraries(test_vtqulator Qt5::Widgets Qt5::Test)
add_executable(run_vtmath VTmath.h VTmath.cpp run_vtmath.cpp)
set_property(TARGET run_vtmath PROPERTY CXX_STANDARD 11)
add_executable(test_vtmath  VTmath.h VTmath.cpp catch.hpp test_vtmath.cpp)
set_property(TARGET test_vtmath PROPERTY CXX_STANDARD 11)
target_link_libraries (run_vtmath ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (vtqulator ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (test_vtqulator ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
add_test(primary_test_for_vtqulator test_vtqulator)
add_test(primary_test_for_vtmath    test_vtmath )

