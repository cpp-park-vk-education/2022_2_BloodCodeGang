//
// Created by Алексей on 12.12.2022.
//


#include <Wt/WApplication.h>
#include <Wt/WServer.h>

#include "include/MenuWidget.h"
//#include "Session.h"


#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WTable.h>



using namespace Wt;
std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment& env) {
    auto app = std::make_unique<Wt::WApplication>(env);

    app->setTitle("Friendify");

//    app->messageResourceBundle().use(app->appRoot() + "strings");
//    app->messageResourceBundle().use(app->appRoot() + "templates");

//    app->useStyleSheet("css/hangman.css");

//    app->useStyleSheet("static/css/bootstrap.css");
//    app->useStyleSheet("static/css/style.css");
    Wt::WApplication::instance()->useStyleSheet("style/CSSexample.css");
    auto container = std::make_unique<Wt::WContainerWidget>();
// The style sheet should be applied to this container only.
// The class .CSS-example is used as selector.
    container->setStyleClass("CSS-example");

    Wt::WPushButton *allB = container->addNew<Wt::WPushButton>("Set all classes");

    Wt::WPushButton *removeB = container->addNew<Wt::WPushButton>("Remove info class");
    removeB->setMargin(10, Wt::Side::Left | Wt::Side::Right);
    removeB->disable();

    Wt::WPushButton *toggleB = container->addNew<Wt::WPushButton>("Toggle compact");
    toggleB->disable();

    Wt::WText *text = container->addNew<Wt::WText>();
    text->setText("<p>These are the most import API classes and methods for"
                  " working with CSS:</p>");

    Wt::WTable *table = container->addNew<Wt::WTable>();
    table->setHeaderCount(1);
    table->elementAt(0, 0)->addNew<Wt::WText>("Method");
    table->elementAt(0, 1)->addNew<Wt::WText>("Description");
    table->elementAt(1, 0)->addNew<Wt::WText>("WApplication::useStyleSheet()");
    table->elementAt(1, 1)->addNew<Wt::WText>("Adds an external style sheet");
    table->elementAt(2, 0)->addNew<Wt::WText>("WWidget::setStyleClass()");
    table->elementAt(2, 1)->addNew<Wt::WText>("Sets (one or more) CSS style classes");
    table->elementAt(3, 0)->addNew<Wt::WText>("WWidget::removeStyleClass()");
    table->elementAt(3, 1)->addNew<Wt::WText>("Removes a CSS style class");
    table->elementAt(4, 0)->addNew<Wt::WText>("WWidget::toggleStyleClass()");
    table->elementAt(4, 1)->addNew<Wt::WText>("Toggles a CSS style class");

    allB->clicked().connect([=] {
        // Set style classes for the complete table.
        table->setStyleClass("table table-bordered");
        // Set the info style class for the first row after the header.
        table->rowAt(1)->setStyleClass("info");
        // Set a style class for the methods (first column, the header excluded).
        for (int i=1; i<table->rowCount(); i++)
            table->elementAt(i,0)->setStyleClass("code");
        removeB->enable();
        toggleB->enable();
    });

    removeB->clicked().connect([=] {
        table->rowAt(1)->removeStyleClass("info");
        removeB->disable();
    });

    toggleB->clicked().connect([=] {
        if (toggleB->text() == "Toggle compact") {
            table->toggleStyleClass("table-sm", true);
            toggleB->setText("Toggle expanded");
        } else {
            table->toggleStyleClass("table-sm", false);
            toggleB->setText("Toggle compact");
        }
    });

//    app->root()->addWidget(std::make_unique<MenuWidget>());
    app->root()->addWidget(std::move(container));

    return app;
}


int main(int argc, char **argv)
{
    try {
        Wt::WServer server(argc, argv, WTHTTP_CONFIGURATION);

        server.addEntryPoint(Wt::EntryPointType::Application, createApplication);

//        Session::configureAuth();

        server.run();
    } catch (Wt::WServer::Exception& e) {
        std::cerr << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
}
