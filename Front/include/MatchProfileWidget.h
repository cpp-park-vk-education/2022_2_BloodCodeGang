//
// Created by Алексей on 12.12.2022.
//

#ifndef MYPROJECT_MATCHPROFILEWIDGET_H
#define MYPROJECT_MATCHPROFILEWIDGET_H

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>


class MatchProfileWidget : public Wt::WContainerWidget {

public:
    MatchProfileWidget();

private:
    Wt::WPushButton* cancel_match_button;
    Wt::WImage* profile_image;
};


#endif //MYPROJECT_MATCHPROFILEWIDGET_H
