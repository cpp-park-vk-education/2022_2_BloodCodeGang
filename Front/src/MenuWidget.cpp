//
// Created by Алексей on 12.12.2022.
//



#include "../include/MenuWidget.h"


MenuWidget::MenuWidget() {
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

    swipeAnchor = links->addWidget(std::make_unique<Wt::WAnchor>("/", "Swipe"));
    swipeAnchor->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/"));

    listingAnchor = links->addWidget(std::make_unique<Wt::WAnchor>("/matches", "Listing"));
    listingAnchor->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/matches"));

    Wt::WApplication::instance()->internalPathChanged()
            .connect(this, &MenuWidget::handleInternalPath);*/




    auto container1 = std::make_unique<Wt::WContainerWidget>();
    container1->setStyleClass("table");
    container1->addWidget(std::make_unique<Wt::WText>("Menu"));
//    std::unique_ptr<Wt::WText> title(std::make_unique<Wt::WText>("Menu"));
//    title->setStyleClass("table");
    addWidget(std::move(container1));

    auto container = std::make_unique<Wt::WContainerWidget>();

    container->addNew<Wt::WText>("A first widget");

    for (unsigned int i = 0; i < 3; ++i) {
        // A widget can be added to a container by using addWidget()
        container->addNew<Wt::WText>(Wt::WString("<p>Text {1}</p>").arg(i));
    }
    addWidget(std::move(container));
//    setStyleClass("container bg-primary");
//    widgets_stack = new Wt::WStackedWidget(); //В этом "контейнере" будет появляться виджет, соответствующий текущему пункту меню
//    widgets_stack->setStyleClass("container");
//    widgets_stack->setPadding(48, Wt::Side::Top); //Потому, что меню будет фиксированным сверху и закроет собой часть этого "контейнера"
//    addWidget(std::unique_ptr<Wt::WStackedWidget>(widgets_stack));
//
//    nav_bar = new Wt::WNavigationBar(); //Сама полосочка меню
//    nav_bar->setTitle("Friendify","http://localhost:8080"); //Красивый заголовок перед пунктами меню, а заодно ссылка
//    nav_bar->setResponsive(true); //Наша полоска будет адаптироваться под размер экрана
//    nav_bar->addStyleClass("container"); //Стиль bootstrap
//    nav_bar->setPositionScheme(Wt::PositionScheme::Fixed); //Делаем полоску меню фиксированной
////    addWidget(std::unique_ptr<Wt::WNavigationBar>(nav_bar));
//
//    left_menu = new Wt::WMenu(widgets_stack); //Создаём новое меню. Заметьте, это именно пункты меню.
//    nav_bar->addMenu(std::unique_ptr<Wt::WMenu>(left_menu)); //Вставляем пункты меню в полоску
//
//    left_menu->addItem(Wt::WString("Swipe"), std::make_unique<Wt::WText>(Wt::WString("This is swipe"))); //Добавляем в меню пункт "Новости".
//
//    addWidget(std::unique_ptr<Wt::WStackedWidget>(widgets_stack)); //Мы создавали контейнер без родителя, и он не будет о
}
