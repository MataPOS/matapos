add_test( ExampleTests.DemonstrateGTestMacros /mnt/d/matapos_6_March/matapos/test/ExampleTest [==[--gtest_filter=ExampleTests.DemonstrateGTestMacros]==] --gtest_also_run_disabled_tests)
set_tests_properties( ExampleTests.DemonstrateGTestMacros PROPERTIES WORKING_DIRECTORY /mnt/d/matapos_6_March/matapos/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( ExampleTest_TESTS ExampleTests.DemonstrateGTestMacros)
