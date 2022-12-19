CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
Project(front)

ADD_EXECUTABLE(front.wt
        front.cpp
        src/MenuWidget.cpp include/MenuWidget.h
        src/MatchesListingWidget.cpp include/MatchesListingWidget.h
        src/SwipeWidget.cpp include/SwipeWidget.h
        src/MatchIconsWidget.cpp include/MatchIconsWidget.h
        src/MatchProfileWidget.cpp include/MatchProfileWidget.h ../Back/src/SwipeResource.cpp ../Back/include/SwipeResource.h
        src/Session.C include/Session.h
        src/User.C include/User.h
        )


INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

INCLUDE_DIRECTORIES(include)
TARGET_LINK_LIBRARIES(front.wt
        Wt::Wt
        Wt::HTTP
        Wt::Dbo
        Wt::DboSqlite3
        ${Boost_FILESYSTEM_LIBRARY}
        )