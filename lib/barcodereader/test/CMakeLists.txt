add_executable(
  barcodereader_test
  barcodereader_test.cpp
)
target_link_libraries(
  barcodereader_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(barcodereader_test)
