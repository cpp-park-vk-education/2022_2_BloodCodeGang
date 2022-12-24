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


    left_menu = navigation->addMenu(std::make_unique<Wt::WMenu>(content_stack));

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
    left_menu->addItem(std::move(item));

    addWidget(std::move(container));

    right_menu = navigation->addMenu(std::make_unique<Wt::WMenu>(content_stack));




    session_.login().changed().connect(this, &MenuWidget::onAuthEvent);

    authModel = std::make_unique<Auth::AuthModel>(Session::auth(), session_.users());
    authModel->addPasswordAuth(&Session::passwordAuth());
    authModel->addOAuth(Session::oAuth());

    authWidget = std::make_unique<Auth::AuthWidget>(session_.login());
    auto authWidgetPtr = authWidget.get();
    authWidget->setModel(std::move(authModel));
    authWidget->setRegistrationEnabled(true);

    authWidget_ = content_stack->addWidget(std::move(authWidget));
    Wt::WApplication::instance()->setInternalPath("/reg", true);
    authWidgetPtr->processEnvironment();
//    showSwipes();
}

void MenuWidget::onAuthEvent() {
    if (session_.login().loggedIn()) {
        a =navigation->addWidget(std::move(content_stack->removeWidget(authWidget_)));
//        authWidget_->hide();
//        handleInternalPath(WApplication::instance()->internalPath());
        Wt::WApplication::instance()->setInternalPath("/", true);
    } else {
//        clear();
//        content_stack->clear();
//        my_matches = nullptr;
//        swipes = nullptr;
//        profile = nullptr;
//        auto t =a;
//        if (!a) {
//            Wt::WApplication::instance()->setInternalPath("/matches", true);
//            return;
//        }
//        auto f = navigation->removeWidget(a);
//        content_stack->addWidget(std::move(f));
        Wt::WApplication::instance()->setInternalPath("/reg", true);
    }
}

void MenuWidget::handleInternalPath(const std::string &internalPath) {
    if (session_.login().loggedIn()) {
        if (internalPath == "/") {
            showSwipes();
        } else if (internalPath == "/matches") {
            showMatchListing();
        }  else if (internalPath == "/reg") {
            showAuth();
        } else if (internalPath == "/profile") {
            showProfile();
        } else {
            Wt::WApplication::instance()->setInternalPath("/", true);
        }
    }
}

void MenuWidget::showMatchListing() {
    if (!my_matches)
        my_matches = content_stack->addWidget(std::make_unique<MatchesListingWidget>());

    content_stack->setCurrentWidget(my_matches);
    auto t = navigation->removeWidget(left_menu);
    if (!t) {
        showProfile();
    }
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

void MenuWidget::showAuth() {
//    if (!authWidget) {
//        authWidget = content_stack->addWidget(std::make_unique<MatchProfileWidget>());
//    }

    content_stack->setCurrentWidget(authWidget_);
}
