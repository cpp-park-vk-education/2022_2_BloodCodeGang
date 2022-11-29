cmake_minimum_required(VERSION 3.1.4)
project(bit_inversion_lib)

file(GLOB SOURCES *.cpp)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${PROJECT_NAME} STATIC ${SOURCES})
