CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
Project(back)

ADD_EXECUTABLE(back.wt
        back.cpp
        )


INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

INCLUDE_DIRECTORIES(include)
TARGET_LINK_LIBRARIES(back.wt
        Wt::Wt
        Wt::HTTP
        ${Boost_FILESYSTEM_LIBRARY}
        )