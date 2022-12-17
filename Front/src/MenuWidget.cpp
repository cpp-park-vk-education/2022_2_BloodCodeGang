//
// Created by Алексей on 12.12.2022.
//



#include "MenuWidget.h"


MenuWidget::MenuWidget() : profile(nullptr), swipes(nullptr), my_matches(nullptr) {
//    session_.login().changed().connect(this, &HangmanGame::onAuthEvent);

//    std::unique_ptr<Auth::AuthModel> authModel
//            = std::make_unique<Auth::AuthModel>(Session::auth(), session_.users());
//    authModel->addPasswordAuth(&Session::passwordAuth());
//    authModel->addOAuth(Session::oAuth());
//
//    std::unique_ptr<Auth::AuthWidget> authWidget
//            = std::make_unique<Auth::AuthWidget>(session_.login());
//    auto authWidgetPtr = authWidget.get();
//    authWidget->setModel(std::move(authModel));
//    authWidget->setRegistrationEnabled(true);

    /*std::unique_ptr<Wt::WText> title(std::make_unique<Wt::WText>("<h1>Menu</h1>"));
    addWidget(std::move(title));

//    addWidget(std::move(authWidget));

    widgetsStack = new Wt::WStackedWidget();
//    mainStack_->setStyleClass("gamestack");
    addWidget(std::unique_ptr<Wt::WStackedWidget>(widgetsStack));

    links = new Wt::WContainerWidget();
    links->setStyleClass("links");
    links->hide();
    addWidget(std::unique_ptr<Wt::WContainerWidget>(links));

    swipe_anchor = links->addWidget(std::make_unique<Wt::WAnchor>("/", "Swipe"));
    swipe_anchor->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/"));

    listing_anchor = links->addWidget(std::make_unique<Wt::WAnchor>("/matches", "Listing"));
    listing_anchor->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/matches"));

    Wt::WApplication::instance()->internalPathChanged()
            .connect(this, &MenuWidget::handleInternalPath);*/




//    auto container = std::make_unique<Wt::WContainerWidget>();
//    container->setStyleClass("table bg-primary");
//    container->addNew<Wt::WText>("A first widget");
//
//    for (unsigned int i = 0; i < 3; ++i) {
//        // A widget can be added to a container by using addWidget()
//        container->addNew<Wt::WText>(Wt::WString("<p>Text {1}</p>").arg(i));
//    }
//    addWidget(std::move(container));



    auto container = std::make_unique<Wt::WContainerWidget>();

    navigation = container->addNew<Wt::WNavigationBar>();
    navigation->setResponsive(true);
    navigation->addStyleClass("navbar navbar-dark bg-primary");
    navigation->setTitle("Friendify","/");
    content_stack = container->addNew<Wt::WStackedWidget>();
    content_stack->addStyleClass("contents");


    left_menu = navigation->addMenu(std::make_unique<Wt::WMenu>(content_stack));


//    auto searchResult = std::make_unique<Wt::WText>("Buy or Sell... Bye!");
//    auto searchResult_ = searchResult.get();
//
//    left_menu->addItem("Home", std::make_unique<Wt::WText>("There is no better place!"));
//    left_menu->addItem("Layout", std::make_unique<Wt::WText>("Layout contents"))
//            ->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/layout"));
//    left_menu->addItem("Sales", std::move(searchResult));
//    left_menu->addStyleClass("me-auto");

// Add a Search control.
//    auto editPtr = std::make_unique<Wt::WLineEdit>();
//    auto edit = editPtr.get();
//    edit->setPlaceholderText("Enter a search item");
//
//    edit->enterPressed().connect([=] {
//        left_menu->select(2); // is the index of the "Sales"
//        searchResult_->setText(Wt::WString("Nothing found for {1}.")
//                                       .arg(edit->text()));
//    });
//
//    navigation->addSearch(std::move(editPtr));


    auto popupPtr = std::make_unique<Wt::WPopupMenu>();
    auto popup = popupPtr.get();

//    links = new Wt::WContainerWidget();
//    links->setStyleClass("links");
//    links->hide();
//    addWidget(std::unique_ptr<Wt::WContainerWidget>(links));
//
//    swipe_anchor = links->addWidget(std::make_unique<Wt::WAnchor>("/", "Swipes"));
//    swipe_anchor->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/"));
//
//    listing_anchor = links->addWidget(std::make_unique<Wt::WAnchor>("/matches", "My Matches"));
//    listing_anchor->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/"));
//
//    profile_anchor = links->addWidget(std::make_unique<Wt::WAnchor>("/profile", "Profile"));
//    profile_anchor->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/profile"));

    popup->addItem("Profile")
        ->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/profile"));
    popup->addItem("Swipes")
            ->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/"));
    popup->addItem("MyMatches")
            ->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/matches"));

    Wt::WApplication::instance()->internalPathChanged()
            .connect(this, &MenuWidget::handleInternalPath);

//    popup->itemSelected().connect([=] (Wt::WMenuItem *item) {
//        auto messageBox = popup->addChild(
//                std::make_unique<Wt::WMessageBox>
//                        ("Help",
//                         Wt::WString("<p>Showing Help: {1}</p>").arg(item->text()),
//                         Wt::Icon::Information,
//                         Wt::StandardButton::Ok));
//
//        messageBox->buttonClicked().connect([=] {
//            popup->removeChild(messageBox);
//        });
//
//        messageBox->show();
//    });


    auto item = std::make_unique<Wt::WMenuItem>("Menu");
    item->setMenu(std::move(popupPtr));
    left_menu->addItem(std::move(item));

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
