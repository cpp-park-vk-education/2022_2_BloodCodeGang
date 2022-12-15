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
    Wt::WApplication::instance()->useStyleSheet("style.css");

    app->root()->addWidget(std::make_unique<MenuWidget>());
//    app->root()->addWidget(std::move(container));

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
