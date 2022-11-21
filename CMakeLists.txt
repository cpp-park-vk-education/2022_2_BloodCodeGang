cmake_minimum_required(VERSION 3.0.0)
project(events)

option(BUILD_FOR_TEST "build for test" OFF)
if(BUILD_FOR_TEST)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0 -Wall -Wextra -Wpedantic -Werror")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
else()
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-O3")
endif()

add_subdirectory(event)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${EVENT_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${EVENT_LIB_LIBRARIES})


if(BUILD_FOR_TEST)
enable_testing()
add_subdirectory(tests)
endif()
