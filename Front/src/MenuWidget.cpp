//
// Created by Алексей on 12.12.2022.
//



#include "../include/MenuWidget.h"


MenuWidget::MenuWidget() {
    std::unique_ptr<Wt::WText> title(std::make_unique<Wt::WText>("<h1>A Witty game: Hangman</h1>"));
    addWidget(std::move(title));
}
