
//
// Created by Алексей on 13.12.2022.
//

#ifndef MYPROJECT_MATCHICONSWIDGET_H
#define MYPROJECT_MATCHICONSWIDGET_H

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>

#include "MatchProfileWidget.h"


class MatchIconsWidget : public Wt::WContainerWidget {

public:
    MatchIconsWidget();

private:
    Wt::WText* name;
    Wt::WText* age;
    Wt::WImage* avatar;
    Wt::WPushButton* contact_button;

    MatchProfileWidget match_profile;
};


#endif //MYPROJECT_MATCHICONSWIDGET_H
