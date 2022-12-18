//
// Created by Алексей on 13.12.2022.
//

#include "MatchIconsWidget.h"


MatchIconsWidget::MatchIconsWidget(std::string avatar_path, std::string name, std::string age) {
    setStyleClass("mb-2 m-3");

    auto image_container = std::make_unique<Wt::WContainerWidget>();
    image_container->setStyleClass("avatar border border-1");
    avatar = image_container->addNew<Wt::WImage>(Wt::WLink(avatar_path));
    avatar->setAlternateText("avatar");
    addWidget(std::move(image_container));


    avatar->clicked().connect([=] (const Wt::WMouseEvent& e) {
        auto messageBox = addChild(
                std::make_unique<Wt::WMessageBox>
                        (name,
                         Wt::WString("<p>Age: {1}</p>").arg(age),
                         Wt::Icon::None,
                         Wt::StandardButton::Ok));
        messageBox->setMinimumSize(400,400);
        messageBox->setClosable(true);
        messageBox->setModal(false);
        messageBox->buttonClicked().connect([=] {
            removeChild(messageBox);
        });

        messageBox->show();
    });



    auto info = std::make_unique<Wt::WTemplate>();
    info->setTemplateText("<div> ${name}, ${age} </div>");
    info->bindString("name", name);
    info->bindString("age", age);
    info->setStyleClass("text-center");
    addWidget(std::move(info));
}

