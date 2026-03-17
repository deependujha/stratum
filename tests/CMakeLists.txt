# ============================================================================
# Tests CMakeLists.txt
# ============================================================================
# This file configures the test suite for the Stratum project.
# Tests are only built when STRATUM_BUILD_TESTS is enabled.
# ============================================================================

if(STRATUM_BUILD_TESTS)
    message(STATUS "Configuring Stratum test suite...")

    # Discover all test source files (.cpp files) in the tests directory
    file(GLOB_RECURSE STRATUM_TEST_SOURCES CONFIGURE_DEPENDS "*.cpp")
    
    if(NOT STRATUM_TEST_SOURCES)
        message(FATAL_ERROR "No test source files found in tests directory")
    endif()

    # Define the test executable
    set(STRATUM_TEST_TARGET stratum_tests)
    add_executable(${STRATUM_TEST_TARGET} ${STRATUM_TEST_SOURCES})

    # Configure include directories for test files (enables IntelliSense)
    target_include_directories(${STRATUM_TEST_TARGET} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${GTEST_INCLUDE_DIRS}
    )

    # Link against GoogleTest main library and the Stratum library
    target_link_libraries(${STRATUM_TEST_TARGET} PRIVATE GTest::gtest_main ${STRATUM_LIB})

    # Enable automatic test discovery with GoogleTest
    include(GoogleTest)
    gtest_discover_tests(${STRATUM_TEST_TARGET}
        DISCOVERY_TIMEOUT 10
        PROPERTIES
            LABELS "unit"
    )

    message(STATUS "Stratum test suite configured successfully")
endif()

