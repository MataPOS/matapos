cmake_minimum_required(VERSION 3.8)

project(matapos)

add_executable(
  ExampleTest
  ExampleTest.cpp
)
target_link_libraries(
  ExampleTest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ExampleTest)
