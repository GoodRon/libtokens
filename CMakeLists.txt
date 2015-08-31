cmake_minimum_required(VERSION 3.1)
project(libtokens)

# GTest
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(GTEST_RESULT_ROOT ${CMAKE_CURRENT_BINARY_DIR}/Testing)
include(CMake/gtest_helper.cmake)
add_custom_target(libtokens_tests_all COMMAND ${CMAKE_CTEST_COMMAND} --verbose)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(.)

add_subdirectory(gtests)

set(SOURCE_FILES
    tokens.cxx
    tokens.h)

add_library(tokens ${SOURCE_FILES})