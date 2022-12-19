//
// Created by Алексей on 12.12.2022.
//



#include "MenuWidget.h"


MenuWidget::MenuWidget() : profile(nullptr), swipes(nullptr), my_matches(nullptr) {
    auto container = std::make_unique<Wt::WContainerWidget>();

    navigation = container->addNew<Wt::WNavigationBar>();
    navigation->setResponsive(true);
    navigation->addStyleClass("navbar navbar-dark bg-primary");
    navigation->setTitle("Friendify","/");
    content_stack = container->addNew<Wt::WStackedWidget>();
    content_stack->addStyleClass("contents");


    menu = navigation->addMenu(std::make_unique<Wt::WMenu>(content_stack));

    auto popupPtr = std::make_unique<Wt::WPopupMenu>();
    auto popup = popupPtr.get();

    popup->addItem("Profile")
        ->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/profile"));
    popup->addItem("Swipes")
            ->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/"));
    popup->addItem("My Matches")
            ->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/matches"));

    Wt::WApplication::instance()->internalPathChanged()
            .connect(this, &MenuWidget::handleInternalPath);

    auto item = std::make_unique<Wt::WMenuItem>("Menu");
    item->setMenu(std::move(popupPtr));
    menu->addItem(std::move(item));

    addWidget(std::move(container));
    showSwipes();
}

void MenuWidget::handleInternalPath(const std::string &internalPath) {
        if (internalPath == "/") {
            showSwipes();
        } else if (internalPath == "/matches") {
            showMatchListing();
        } else if (internalPath == "/profile") {
            showProfile();
        } else {
            Wt::WApplication::instance()->setInternalPath("/", true);
        }
}

void MenuWidget::showMatchListing() {
    if (!my_matches)
        my_matches = content_stack->addWidget(std::make_unique<MatchesListingWidget>());

    content_stack->setCurrentWidget(my_matches);
}

void MenuWidget::showSwipes() {
    if (!swipes) {
        swipes = content_stack->addWidget(std::make_unique<SwipeWidget>());
    }

    content_stack->setCurrentWidget(swipes);
}

void MenuWidget::showProfile() {
    if (!profile) {
        profile = content_stack->addWidget(std::make_unique<MatchProfileWidget>());
    }

    content_stack->setCurrentWidget(profile);
}
