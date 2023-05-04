cmake_minimum_required(VERSION 3.0.0)
project(ORM_project_part VERSION 0.1.0)

add_subdirectory(lib/DatabaseMOCK)
add_subdirectory(lib/ORM)
add_subdirectory(lib/ORMGenerator)

add_executable(ORM_project_part src/main.cpp)
target_link_libraries(ORM_project_part DatabaseMOCK)
target_link_libraries(ORM_project_part ORM)
target_link_libraries(ORM_project_part ORMGenerator)