//
// Created by Алексей on 12.12.2022.
//

#ifndef MYPROJECT_MENUWIDGET_H
#define MYPROJECT_MENUWIDGET_H

#include <Wt/WAnchor.h>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WLink.h>
#include <Wt/WMenu.h>
#include <Wt/WMessageBox.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WPopupMenuItem.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WText.h>

#include "MatchesListingWidget.h"
#include "MatchProfileWidget.h"
#include "SwipeWidget.h"



class MenuWidget : public Wt::WContainerWidget {

public:
    MenuWidget();

private:
//    void onAuthEvent();
    void handleInternalPath(const std::string &internalPath);
    void showMatchListing();
    void showProfile();
    void showSwipes();

    Wt::WStackedWidget* content_stack;
    Wt::WNavigationBar* navigation;
    Wt::WMenu* menu;

    MatchProfileWidget* profile;
    SwipeWidget* swipes;
    MatchesListingWidget* my_matches;
};


#endif //MYPROJECT_MENUWIDGET_H
