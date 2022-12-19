//
// Created by Алексей on 12.12.2022.
//

#include <Wt/WApplication.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WResource.h>
#include <Wt/WServer.h>

#include "SwipeResource.h"


using namespace Wt;
std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment& env) {
    auto app = std::make_unique<Wt::WApplication>(env);

    app->setTitle("FriendifyAPI");

//    app->useStyleSheet("css/style.css");
//    app->setTheme(std::make_shared<Wt::WBootstrap5Theme>());
//    app->root()->addWidget(std::make_unique<MenuWidget>());
    return app;
}


int main(int argc, char **argv) {
    try {
        Wt::WServer server(argc, argv, WTHTTP_CONFIGURATION);

//        server.addEntryPoint(Wt::EntryPointType::Application, createApplication);
        server.addResource(new SwipeResource, "/swipe");
        server.run();
    } catch (Wt::WServer::Exception& e) {
        std::cerr << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
}
