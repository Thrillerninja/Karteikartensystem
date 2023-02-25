add_test([=[HelloTest.BasicAssertions]=]  [==[C:/$$Meine Daten/Studium/Programmieren 1/Karteikartensystem/build/Debug/hello_test.exe]==] [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HelloTest.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY [==[C:/$$Meine Daten/Studium/Programmieren 1/Karteikartensystem/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  hello_test_TESTS HelloTest.BasicAssertions)
