cmake_minimum_required(VERSION 3.0.0)
project(Project_H VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Project_H main.cpp prim.h prim.cpp fibnode.h fibheap.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
