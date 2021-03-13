cmake_minimum_required(VERSION 3.13)  # CMake version check
project(simple_example)               # Create project "simple_example"
set(CMAKE_C_STANDARD 99)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES loop_bonus.c parser_bonus.c)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(simple_example ${SOURCE_FILES})