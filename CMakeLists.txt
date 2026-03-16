cmake_minimum_required(VERSION 4.2.0)
project(Stratum VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing at root level so CTest can find it
enable_testing()

# Declare Options
option(STRATUM_BUILD_TESTS "Build tests" OFF)

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
