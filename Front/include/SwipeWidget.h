//
// Created by Алексей on 12.12.2022.
//

#ifndef MYPROJECT_SWIPEWIDGET_H
#define MYPROJECT_SWIPEWIDGET_H

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WPushButton.h>


class SwipeWidget : public Wt::WContainerWidget{

public:
    SwipeWidget();

private:
    Wt::WPushButton* like;
    Wt::WPushButton* dislike;
    Wt::WImage* avatar;
};


#endif //MYPROJECT_SWIPEWIDGET_H
