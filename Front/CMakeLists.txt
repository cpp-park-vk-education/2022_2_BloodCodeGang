CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
Project(front)

ADD_EXECUTABLE(front.wt
        front.cpp
        src/MenuWidget.cpp include/MenuWidget.h
        )
#         Front/src/MenuWidget.cpp Front/include/MenuWidget.h Front/src/SwipeWidget.cpp Front/include/SwipeWidget.h Front/src/MatchProfileWidget.cpp Front/include/MatchProfileWidget.h Front/src/MatchesListingWidget.cpp Front/include/MatchesListingWidget.h)


TARGET_LINK_LIBRARIES(front.wt
        Wt::Wt
        Wt::HTTP
        #   debug libhpdfd optimized libhpdf # only required for if you write pdfs
        )