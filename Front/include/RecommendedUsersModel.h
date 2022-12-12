//
// Created by Алексей on 21.11.2022.
//

#ifndef ALGOS_RECOMMENDEDUSERSMODEL_H
#define ALGOS_RECOMMENDEDUSERSMODEL_H


#include "UserInfo.h"


class IMatchModel {
public:
    virtual UserInfo getUserInfo() = 0;
};

class RecommendedUsersModel : public IMatchModel{
public:

    virtual UserInfo getUserInfo() override;
};


#endif //ALGOS_RECOMMENDEDUSERSMODEL_H
