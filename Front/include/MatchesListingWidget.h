//
// Created by Алексей on 12.12.2022.
//

#ifndef MYPROJECT_MATCHESLISTINGWIDGET_H
#define MYPROJECT_MATCHESLISTINGWIDGET_H

#include <Wt/WContainerWidget.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WToolBar.h>

#include "MatchIconsWidget.h"


class MatchesListingWidget : public Wt::WContainerWidget {

public:
    MatchesListingWidget();

private:
    std::vector<Wt::WImage*> match_icons;
    Wt::WPushButton* cancel_match_button;

};


#endif //MYPROJECT_MATCHESLISTINGWIDGET_H
