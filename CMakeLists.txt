 CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
 Project(myproject)
 set(CMAKE_CXX_STANDARD 17)

 FIND_PACKAGE(Wt REQUIRED Wt HTTP)

 ADD_DEFINITIONS(-DHPDF_DLL)

 ADD_EXECUTABLE(myprog.wt
         source/hello.cpp
         Front/src/MenuWidget.cpp Front/include/MenuWidget.h Front/src/SwipeWidget.cpp Front/include/SwipeWidget.h Front/src/MatchProfileWidget.cpp Front/include/MatchProfileWidget.h Front/src/MatchesListingWidget.cpp Front/include/MatchesListingWidget.h)

 TARGET_LINK_LIBRARIES(myprog.wt
   Wt::Wt
   Wt::HTTP
#   debug libhpdfd optimized libhpdf # only required for if you write pdfs
 )

#cmake_minimum_required(VERSION 3.19)
#project(WT_EXAMPLE)
#
#set(CMAKE_CXX_STANDARD 17)
#
##SET (WT_CONNECTOR "wthttp" CACHE STRING "Connector used (wthttp or wtfcgi)")
#
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeFiles")
#
#find_package(Boost COMPONENTS system thread signals)
#include_directories(${Boost_INCLUDE_DIRS})
#set(libs ${libs} ${Boost_LIBRARIES})
#
#FIND_PACKAGE(Wt REQUIRED)
#INCLUDE_DIRECTORIES(${Wt_INCLUDE_DIR})
#
#SET(WT_PROJECT_SOURCE
#        source/hello.cpp
#        )
#
#
#SET(WT_PROJECT_TARGET hello.wt)
#
#ADD_EXECUTABLE(${WT_PROJECT_TARGET} ${WT_PROJECT_SOURCE})
#
#TARGET_LINK_LIBRARIES(${WT_PROJECT_TARGET} ${libs} ${Wt_DEBUG_LIBRARY} ${Wt_HTTP_DEBUG_LIBRARY} )

#ADD_SUBDIRECTORY(source)

#option(BUILD_FOR_TEST "build for test" OFF)
#if(BUILD_FOR_TEST)
#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0 -Wall -Wextra -Wpedantic -Werror")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
#else()
#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-O3")
#endif()
#
#add_subdirectory(bitCounter)
#add_subdirectory(memoryError)
#add_subdirectory(bitInversion)
#
#
#message("BIT_LIB_LIBRARIES = ${BIT_LIB_LIBRARIES}")
#message("BIT_LIB_INCLUDE_DIRS = ${BIT_LIB_INCLUDE_DIRS}")
#
#message("MEMORYERROR_LIB_LIBRARIES = ${MEMORYERROR_LIB_LIBRARIES}")
#message("MEMORYERROR_LIB_INCLUDE_DIRS = ${MEMORYERROR_LIB_INCLUDE_DIRS}")
#
#message("BIT_INV_LIB_INCLUDE_DIRS = ${BIT_INV_LIB_INCLUDE_DIRS}")
#message("BIT_INV_LIB_LIBRARIES = ${BIT_INV_LIB_LIBRARIES}")
#
#add_executable(${PROJECT_NAME} main.cpp source/hello.cpp)
#
#target_include_directories(${PROJECT_NAME} PUBLIC ${BIT_LIB_INCLUDE_DIRS} ${MEMORYERROR_LIB_INCLUDE_DIRS} ${BIT_INV_LIB_INCLUDE_DIRS})
#target_link_libraries(${PROJECT_NAME} PRIVATE ${BIT_LIB_LIBRARIES} ${MEMORYERROR_LIB_LIBRARIES} ${BIT_INV_LIB_LIBRARIES})

# target_include_directories(${PROJECT_NAME} PUBLIC ${MEMORYERROR_LIB_INCLUDE_DIRS})
# target_link_libraries(${PROJECT_NAME} PRIVATE ${MEMORYERROR_LIB_LIBRARIES})

# target_include_directories(${PROJECT_NAME} PUBLIC ${BIT_INV_LIB_INCLUDE_DIRS})
# target_link_libraries(${PROJECT_NAME} PRIVATE ${BIT_INV_LIB_LIBRARIES})

#if(BUILD_FOR_TEST)
#enable_testing()
#add_subdirectory(tests)
#endif()
