//
// Created by Алексей on 21.11.2022.
//

#ifndef ALGOS_USERESTIMATIONMODEL_H
#define ALGOS_USERESTIMATIONMODEL_H


#include "UserInfo.h"


class IUserEstimationModel {
public:
    virtual void updateInfo(bool new_like_value, UserInfo new_user_info) = 0;
};

class UserEstimationModel : public IUserEstimationModel {
public:

    virtual void updateInfo(bool new_like_value, UserInfo new_user_info) override;
private:

    bool like;
    UserInfo user_info;
};


#endif //ALGOS_USERESTIMATIONMODEL_H
