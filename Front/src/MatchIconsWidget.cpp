//
// Created by Алексей on 13.12.2022.
//

#include "MatchIconsWidget.h"


MatchIconsWidget::MatchIconsWidget(std::string avatar_path, std::string name, std::string age) {
    setStyleClass("container my-3 w-25 h-25 d-flex flex-wrap");

    auto image_container = std::make_unique<Wt::WContainerWidget>();
    image_container->setStyleClass("avatar");
    avatar = image_container->addNew<Wt::WImage>(Wt::WLink(avatar_path));
    avatar->setAlternateText("avatar");
    addWidget(std::move(image_container));

    auto info = std::make_unique<Wt::WTemplate>();
    info->setTemplateText("<div> ${name}, ${age} </div>");
    info->bindString("name", name);
    info->bindString("age", age);
    info->setStyleClass("d-flex justify-content-center");
    addWidget(std::move(info));
}

