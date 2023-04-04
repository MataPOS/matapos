add_executable(
  window_test
  window_test.cpp
)
target_link_libraries(
  window_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(window_test)
