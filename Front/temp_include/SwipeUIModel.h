//
// Created by Алексей on 21.11.2022.
//

#ifndef ALGOS_SWIPEUIMODEL_H
#define ALGOS_SWIPEUIMODEL_H

#include "MatchController.h"

class ISwipeUIModel {
public:
    virtual void getNextUser(bool like_value) = 0;
};

class SwipeUIModel : public ISwipeUIModel{
public:

    virtual void getNextUser(bool like_value) override;

private:

    IMatchModel *recommendedUsers;
    IUserEstimation user_estimation;
     ActionBus *actions;
    UserInfo currenSwipe;
};


#endif //ALGOS_SWIPEUIMODEL_H
