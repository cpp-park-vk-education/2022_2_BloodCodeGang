//
// Created by Алексей on 21.11.2022.
//

#ifndef ALGOS_MATCHCANCELREPORTERMODEL_H
#define ALGOS_MATCHCANCELREPORTERMODEL_H


#include "UserInfo.h"


class IMatchCancelReporterModel {
public:
     virtual void updateInfo(UserInfo new_user_info) = 0;
};

class MatchCancelReporterModel : public IMatchCancelReporterModel{
public:

    virtual void updateInfo(UserInfo new_user_info) override;
private:

    UserInfo user_info;
};


#endif //ALGOS_MATCHCANCELREPORTERMODEL_H
