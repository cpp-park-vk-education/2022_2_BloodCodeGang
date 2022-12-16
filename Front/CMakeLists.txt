CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
Project(front)

ADD_EXECUTABLE(front.wt
        front.cpp
        src/MenuWidget.cpp include/MenuWidget.h
        src/MatchesListingWidget.cpp include/MatchesListingWidget.h
        #[[src/MatchIconsWidget.cpp include/MatchIconsWidget.h]])
#         Front/src/MenuWidget.cpp Front/include/MenuWidget.h Front/src/SwipeWidget.cpp Front/include/SwipeWidget.h Front/src/MatchProfileWidget.cpp Front/include/MatchProfileWidget.h Front/src/MatchesListingWidget.cpp Front/include/MatchesListingWidget.h)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

INCLUDE_DIRECTORIES(include)
TARGET_LINK_LIBRARIES(front.wt
        Wt::Wt
        Wt::HTTP
        ${Boost_FILESYSTEM_LIBRARY}
        )