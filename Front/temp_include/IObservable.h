//
// Created by Алексей on 21.11.2022.
//

#ifndef ALGOS_IOBSERVABLE_H
#define ALGOS_IOBSERVABLE_H

#include "Action.h"

class IObservable {
public:
    virtual void update(Action action) = 0;
};


#endif //ALGOS_IOBSERVABLE_H
