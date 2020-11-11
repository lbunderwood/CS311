cmake_minimum_required(VERSION 3.0.0)
project(Project_7 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Project_7 treesort_test.cpp treesort.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
