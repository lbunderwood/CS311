cmake_minimum_required(VERSION 3.0.0)
project(Project_2 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Project_2 msarray_test.cpp msarray.h doctest.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
