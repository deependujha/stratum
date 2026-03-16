cmake_minimum_required(VERSION 3.21)
project(Stratum VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable testing at root level so CTest can find it
enable_testing()

# Declare Options
option(STRATUM_BUILD_TESTS "Build tests" OFF)

# Set Variable names
set(STRATUM_LIB stratum)
set(STRATUM_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(STRATUM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(STRATUM_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(STRATUM_TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# utility functions

function (build_tests)
    message("Building Stratum tests...")
    add_subdirectory(external/googletest)
    add_subdirectory(tests)
    message("Stratum tests built successfully.")
endfunction()

# Add subdirectories
add_subdirectory(lib)
add_subdirectory(src)

# Build tests if enabled

if(STRATUM_BUILD_TESTS)
    build_tests()
endif()
