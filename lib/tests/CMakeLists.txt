add_executable(tests src/test_ORM.cpp)
target_link_libraries(tests ORM GTest::gtest_main)

add_test(tests tests)