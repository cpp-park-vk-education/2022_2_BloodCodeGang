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
add_subdirectory(memoryError)
add_subdirectory(bit_inversion)


message("BIT_LIB_LIBRARIES = ${BIT_LIB_LIBRARIES}")
message("BIT_LIB_INCLUDE_DIRS = ${BIT_LIB_INCLUDE_DIRS}")

message("MEMORYERROR_LIB_LIBRARIES = ${MEMORYERROR_LIB_LIBRARIES}")
message("MEMORYERROR_LIB_INCLUDE_DIRS = ${MEMORYERROR_LIB_INCLUDE_DIRS}")

message("BIT_INV_LIB_INCLUDE_DIRS = ${BIT_INV_LIB_INCLUDE_DIRS}")
message("BIT_INV_LIB_LIBRARIES = ${BIT_INV_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${BIT_LIB_INCLUDE_DIRS} ${MEMORYERROR_LIB_INCLUDE_DIRS} ${BIT_INV_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${BIT_LIB_LIBRARIES} ${MEMORYERROR_LIB_LIBRARIES} ${BIT_INV_LIB_LIBRARIES})

# target_include_directories(${PROJECT_NAME} PUBLIC ${MEMORYERROR_LIB_INCLUDE_DIRS})
# target_link_libraries(${PROJECT_NAME} PRIVATE ${MEMORYERROR_LIB_LIBRARIES})

# target_include_directories(${PROJECT_NAME} PUBLIC ${BIT_INV_LIB_INCLUDE_DIRS})
# target_link_libraries(${PROJECT_NAME} PRIVATE ${BIT_INV_LIB_LIBRARIES})

if(BUILD_FOR_TEST)
enable_testing()
add_subdirectory(tests)

add_custom_command (TARGET ${PROJECT_NAME}
    COMMAND bash -c "valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes $<TARGET_FILE:${PROJECT_NAME}>"
)
endif()
