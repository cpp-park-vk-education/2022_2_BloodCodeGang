//
// Created by Алексей on 21.11.2022.
//

#ifndef ALGOS_MATCHCONTROLLER_H
#define ALGOS_MATCHCONTROLLER_H


#include "SwipeUIModel.h"
#include "MatchListingModel.h"


class IMatchController {
public:

    virtual void estimate(bool like) = 0;
    virtual void clickUserInfo() = 0;
    virtual void cancelMatch() = 0;
};

class MatchController : public IMatchController{

public:

    virtual void estimate(bool like) override;
    virtual void clickUserInfo() override;
    virtual void cancelMatch() override;

private:
    ISwipeUIModel *estimation;
    IMatchCancelerModel *match_canceler ;
};


#endif //ALGOS_MATCHCONTROLLER_H
