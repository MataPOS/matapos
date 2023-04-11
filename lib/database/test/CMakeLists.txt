add_executable(
  database_test
  
  database_test.cpp
)
target_link_libraries(
  database_test
  
  GTest::gtest_main
  database
  entity
)

include(GoogleTest)
gtest_discover_tests(database_test)
