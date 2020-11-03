cmake_minimum_required(VERSION 3.0.0)
project(Project_6 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Project_6 doctest.h dp6_test.cpp dp6.h llnode2.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
