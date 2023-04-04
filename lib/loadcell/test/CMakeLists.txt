add_executable(
  loadcell_test
  loadcell_test.cpp
)
target_link_libraries(
  loadcell_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(loadcell_test)
