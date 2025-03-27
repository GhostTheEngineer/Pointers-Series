cmake_minimum_required(VERSION 3.10)
project(test_program)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ensure SELECTED_FILE is provided
if(NOT DEFINED SELECTED_FILE)
    message(FATAL_ERROR "No source file selected. Run CMake with -DSELECTED_FILE=<file>.cpp")
endif()

# Ensure OPTIMIZATION_LEVEL is provided
if(NOT DEFINED OPTIMIZATION_LEVEL)
    message(FATAL_ERROR "No optimization level set. Run CMake with -DOPTIMIZATION_LEVEL=-O0 or -O2")
endif()

# Trim any accidental quotes around parameters
string(REPLACE "\"" "" SELECTED_FILE ${SELECTED_FILE})
string(REPLACE "\"" "" OPTIMIZATION_LEVEL ${OPTIMIZATION_LEVEL})

# Set the selected file path
set(SOURCE_FILE "${CMAKE_SOURCE_DIR}/src/${SELECTED_FILE}")

# Check if the file exists
if(NOT EXISTS ${SOURCE_FILE})
    message(FATAL_ERROR "Selected file '${SOURCE_FILE}' does not exist in src/.")
endif()

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILE})

# Enable warnings
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 ${OPTIMIZATION_LEVEL})
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic ${OPTIMIZATION_LEVEL})
endif()
