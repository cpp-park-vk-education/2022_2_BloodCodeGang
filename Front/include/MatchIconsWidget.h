
//
// Created by Алексей on 13.12.2022.
//

#ifndef MYPROJECT_MATCHICONSWIDGET_H
#define MYPROJECT_MATCHICONSWIDGET_H

#include <Wt/WContainerWidget.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WText.h>
#include <Wt/WTemplate.h>
#include <Wt/WMessageBox.h>

#include "MatchProfileWidget.h"


class MatchIconsWidget : public Wt::WContainerWidget {

public:
    MatchIconsWidget(std::string avatar_path, std::string name  = "name", std::string age = "age");

private:
    Wt::WText* name;
    Wt::WText* age;
    Wt::WImage* avatar;
    Wt::WPushButton* contact_button;

    MatchProfileWidget match_profile;
};


#endif //MYPROJECT_MATCHICONSWIDGET_H
