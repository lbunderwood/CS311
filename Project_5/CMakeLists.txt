cmake_minimum_required(VERSION 3.0.0)
project(TFS_Array VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(TFS_Array tfsarray_test.cpp tfsarray.h doctest.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
