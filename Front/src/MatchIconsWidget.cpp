//
// Created by Алексей on 13.12.2022.
//

#include "../include/MatchIconsWidget.h"


MatchIconsWidget::MatchIconsWidget() {
    std::unique_ptr <Wt::WText> title(std::make_unique<Wt::WText>("<h1>This is match icon</h1>"));
    addWidget(std::move(title));
}