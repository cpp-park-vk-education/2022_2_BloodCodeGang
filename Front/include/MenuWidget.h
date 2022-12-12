//
// Created by Алексей on 12.12.2022.
//

#ifndef MYPROJECT_MENUWIDGET_H
#define MYPROJECT_MENUWIDGET_H

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>


#include "MatchesListingWidget.h"
#include "MatchProfileWidget.h"
#include "SwipeWidget.h"


class MenuWidget : public Wt::WContainerWidget {

public:
    MenuWidget();

private:
//    void onAuthEvent();
    void showMatchListing();
    void showMatchProfile();

    Wt::WStackedWidget* mainStack_;
    Wt::WNavigationBar* navbar;
    Wt::WMenu* left_menu;
    Wt::WMenuItem* profile;
    Wt::WMenuItem* recommended;
    Wt::WMenuItem* my_matches;

    MatchesListingWidget match_listing;
    MatchProfileWidget match_profile;
    SwipeWidget swipe;
};


#endif //MYPROJECT_MENUWIDGET_H
