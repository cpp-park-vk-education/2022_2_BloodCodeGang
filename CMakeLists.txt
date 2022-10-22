cmake_minimum_required(VERSION 3.0.0)
project(bit)

add_subdirectory(BitCounter)
add_subdirectory(memoryError)

message("BIT_LIB_LIBRARIES = ${BIT_LIB_LIBRARIES}")
message("BIT_LIB_INCLUDE_DIRS = ${BIT_LIB_INCLUDE_DIRS}")

message("MEMORYERROR_LIB_LIBRARIES = ${MEMORYERROR_LIB_LIBRARIES}")
message("MEMORYERROR_LIB_INCLUDE_DIRS = ${MEMORYERROR_LIB_INCLUDE_DIRS}")

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${BIT_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${BIT_LIB_LIBRARIES})

target_include_directories(${PROJECT_NAME} PUBLIC ${MEMORYERROR_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${MEMORYERROR_LIB_LIBRARIES})

add_custom_command (TARGET ${PROJECT_NAME}
    COMMAND bash -c "valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes $<TARGET_FILE:${PROJECT_NAME}>"
)