//
// Created by Алексей on 12.12.2022.
//

#include "MatchesListingWidget.h"

MatchesListingWidget::MatchesListingWidget() {
    std::unique_ptr<Wt::WText> title(std::make_unique<Wt::WText>("<h2>This is match listing</h2>"));
    addWidget(std::move(title));
}