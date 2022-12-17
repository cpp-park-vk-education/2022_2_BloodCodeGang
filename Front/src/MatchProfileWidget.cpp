//
// Created by Алексей on 12.12.2022.
//

#include "MatchProfileWidget.h"


MatchProfileWidget::MatchProfileWidget() {
    std::unique_ptr <Wt::WText> title(std::make_unique<Wt::WText>("<h3>This is match profile</h3>"));
    addWidget(std::move(title));
}
