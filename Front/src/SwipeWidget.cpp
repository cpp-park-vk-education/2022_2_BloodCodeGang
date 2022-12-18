//
// Created by Алексей on 12.12.2022.
//

#include "SwipeWidget.h"


SwipeWidget::SwipeWidget() {
    setStyleClass("row pt-4 px-3 mt-5 vh-100");


    auto left = addNew<Wt::WContainerWidget>();
    left->setStyleClass("col-6");
    avatar = left->addNew<Wt::WImage>(Wt::WLink("icons/a1.jpeg"));
    avatar->setAlternateText("avatar");
    avatar->setStyleClass("img-fluid border border-3 rounded");

    auto button_panel = left->addNew<Wt::WContainerWidget>();
    button_panel->setStyleClass("mt-2 px-5 mx-2");

    dislike = button_panel->addNew<Wt::WPushButton>();
    dislike->setStyleClass("float-start");
    dislike->setIcon("icons/dislike.svg");

    like = button_panel->addNew<Wt::WPushButton>();
    like->setStyleClass("float-end");
    like->setIcon("icons/like.svg");


    auto right = addNew<Wt::WContainerWidget>();
    right->setStyleClass("col-6");

    auto info = right->addNew<Wt::WContainerWidget>();
    info->setStyleClass("container rounded bg-secondary h-50 pt-2");
    info->addNew<Wt::WText>("<h2>Name, Age</h2>");
    info->addNew<Wt::WText>("Description");
}