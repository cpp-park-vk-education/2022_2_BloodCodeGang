//
// Created by Алексей on 12.12.2022.
//

#ifndef MYPROJECT_MATCHESLISTINGWIDGET_H
#define MYPROJECT_MATCHESLISTINGWIDGET_H

#include "MatchIconsWidget.h"


class MatchesListingWidget : public Wt::WContainerWidget {

public:
    MatchesListingWidget();

private:
    std::vector<MatchIconsWidget> match_icons;
    Wt::WPushButton* cancel_match_button;
    Wt::WImage* profile_image;

};


#endif //MYPROJECT_MATCHESLISTINGWIDGET_H
