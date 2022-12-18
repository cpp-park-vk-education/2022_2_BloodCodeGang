//
// Created by Алексей on 12.12.2022.
//

#include "MatchesListingWidget.h"

MatchesListingWidget::MatchesListingWidget() {
//    auto toolBar = addNew<Wt::WToolBar>();
//
//    addWidget(std::unique_ptr<Wt::WToolBar>(toolBar));
//    addWidget(std::make_unique<MatchIconsWidget>());
//    addWidget(std::move(title));
//    for (auto i : match_icons) {
//        i = addWidget(std::unique_ptr<MatchIconsWidget>());
//    }
    setStyleClass("ps-2 mt-2 listing");
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a1.jpeg", "Dantalian", "1050"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a2.jpg", "Juliet", "18"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a3.jpg", "Sushi", "1800"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a4.jpg", "Paul", "18"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a5.png", "Director", "65"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a6.png", "Astarot", "2056"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a6.png", "Astarot", "2056"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a6.png", "Astarot", "2056"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a6.png", "Astarot", "2056"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a6.png", "Astarot", "2056"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a6.png", "Astarot", "2056"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a6.png", "Astarot", "2056"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a6.png", "Astarot", "2056"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a6.png", "Astarot", "2056"));
    addNewMatch(std::make_unique<MatchIconsWidget>("icons/a6.png", "Astarot", "2056"));
//    std::unique_ptr <Wt::WText> title(std::make_unique<Wt::WText>("<h3>This is listing</h3>"));
//    addWidget(std::move(title));
}

int MatchesListingWidget::addNewMatch(std::unique_ptr<MatchIconsWidget> match) {
    addWidget(std::move(match));
    return 0;
}
