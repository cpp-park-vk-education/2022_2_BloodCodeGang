//
// Created by Алексей on 21.11.2022.
//

#ifndef ALGOS_ACTION_H
#define ALGOS_ACTION_H

#include "UserInfo.h"


enum Type {
    NEXT_SWIPE,
    NEW_MATCH,
    MATCH_CANCEL,
};

struct Action {
    Type type;
    UserInfo new_swipe_info;
    UserInfo new_matched_user;
};

#endif //ALGOS_ACTION_H
