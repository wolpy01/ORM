add_executable(utils_test src/DatabaseMOCK.cpp)
target_link_libraries(utils_test lib/DatabaseMOCK GTest::gtest_main)
target_link_libraries(utils_test lib/ORM GTest::gtest_main)

add_test(utils_test utils_test)
