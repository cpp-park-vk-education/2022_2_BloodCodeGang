//
// Created by Алексей on 12.12.2022.
//

#include "SwipeWidget.h"


SwipeWidget::SwipeWidget() {
    setStyleClass("row mt-3 px-3 vh-100");


    auto left = addNew<Wt::WContainerWidget>();
    left->setStyleClass("col-6 col-6 d-flex flex-column align-items-center");
//    avatar = left->addNew<Wt::WImage>(Wt::WLink("icons/a3.jpg"));
//    avatar->setAlternateText("avatar");
//    avatar->setStyleClass("img-fluid border border-3 rounded");

    auto image_container = std::make_unique<Wt::WContainerWidget>();
    image_container->setStyleClass("avatar avatar-swipes");
    avatar = image_container->addNew<Wt::WImage>(Wt::WLink("icons/a3.jpg"));
    avatar->setAlternateText("avatar");
    left->addWidget(std::move(image_container));

    auto button_panel = left->addNew<Wt::WContainerWidget>();
    button_panel->setStyleClass("mt-2 container w-50");

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