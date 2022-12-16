//
// Created by Алексей on 12.12.2022.
//

#ifndef MYPROJECT_MENUWIDGET_H
#define MYPROJECT_MENUWIDGET_H

#include <Wt/WAnchor.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLink.h>
#include <Wt/WStackedWidget.h>

#include <Wt/WLineEdit.h>
#include <Wt/WMenu.h>
#include <Wt/WMessageBox.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WPopupMenuItem.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WText.h>



class MenuWidget : public Wt::WContainerWidget {

public:
    MenuWidget();

private:
//    void onAuthEvent();
    void showMatchListing();
    void showMatchProfile();

    Wt::WStackedWidget* content_stack;
    Wt::WNavigationBar* nav_bar;
    Wt::WMenu* left_menu;

    Wt::WContainerWidget* links;
    Wt::WMenuItem* profile;
    Wt::WMenuItem* recommended;
    Wt::WMenuItem* my_matches;

    Wt::WAnchor* swipeAnchor;
    Wt::WAnchor* listingAnchor;

//    MatchesListingWidget match_listing;
//    SwipeWidget swipe;
};


#endif //MYPROJECT_MENUWIDGET_H
