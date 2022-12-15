//
// Created by Алексей on 12.12.2022.
//

#include "../include/MatchProfileWidget.h"


MatchProfileWidget::MatchProfileWidget() {
    std::unique_ptr <Wt::WText> title(std::make_unique<Wt::WText>("<h1>This is match profile</h1>"));
    addWidget(std::move(title));
}
