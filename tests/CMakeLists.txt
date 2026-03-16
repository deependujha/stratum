if(STRATUM_BUILD_TESTS)
  add_executable(
    sample_test
    sample_test.cpp
  )
  target_link_libraries(
    sample_test
    GTest::gtest_main
  )

  include(GoogleTest)
  gtest_discover_tests(sample_test)
endif()
