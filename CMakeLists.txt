cmake_minimum_required(VERSION 3.0.0)
project(ORM VERSION 0.1.0)

add_subdirectory(lib/ORM)
add_subdirectory(lib/ORMGenerator)

add_executable(ORM src/main.cpp)
target_link_libraries(ORM ORM)
target_link_libraries(ORM ORMGenerator)