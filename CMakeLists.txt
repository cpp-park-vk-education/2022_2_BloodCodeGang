cmake_minimum_required(VERSION 3.0.0)
project(bit)

option(BUILD_FOR_TEST "build for test" OFF)
if(BUILD_FOR_TEST)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0 -Wall -Wextra -Wpedantic -Werror")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
else()
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-O3")
endif()

add_subdirectory(BitCounter)

message("BIT_LIB_LIBRARIES = ${BIT_LIB_LIBRARIES}")
message("BIT_LIB_INCLUDE_DIRS = ${BIT_LIB_INCLUDE_DIRS}")

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${BIT_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${BIT_LIB_LIBRARIES})