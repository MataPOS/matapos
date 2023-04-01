cmake_minimum_required(VERSION 3.8)

project(matapos)

add_executable(
  camera_test
  camera_test.cpp
)
target_link_libraries(
  camera_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(camera_test)
