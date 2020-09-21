cmake_minimum_required(VERSION 3.0.0)
project(Project_3 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Project_3 dp3_test.cpp dp3.cpp dp3.h llnode.h doctest.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
