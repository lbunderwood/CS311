cmake_minimum_required(VERSION 3.0.0)
project(Project_4 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Project_4 counthsw_test.cpp counthsw.cpp counthsw.h doctest.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
