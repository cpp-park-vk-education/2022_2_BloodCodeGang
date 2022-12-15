//
// Created by Алексей on 21.11.2022.
//

#ifndef ALGOS_MATCHLISTINGMODEL_H
#define ALGOS_MATCHLISTINGMODEL_H

#include "UserInfo.h"

#include <vector>


class IMatchCancelerModel {
public:

    virtual void cancelMatch(UserInfo user_info) = 0;
};

class INewMatchModel {
public:

    virtual void addNewMatch(UserInfo new_user_info) = 0;
};

class IMatchListingModel {
public:

    virtual std::vector<UserInfo> getUsersInfo() = 0;
};

class MatchListingModel : public IMatchListingModel, INewMatchModel, IMatchCancelerModel {
public:

    virtual std::vector<UserInfo> getUsersInfo() override;
    virtual void addNewMatch(UserInfo new_user_info) override;
    virtual void cancelMatch(UserInfo user_info) override;

};


#endif //ALGOS_MATCHLISTINGMODEL_H
