cmake_minimum_required(VERSION 3.10)

project(ae)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  message(STATUS "Debug mode detected")

  enable_testing()
  add_subdirectory(tests)

elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
  message(STATUS "Release mode detected")
else ()
  message(FATAL_ERROR "Undefined build mode")
endif ()