//
// Created by Алексей on 21.11.2022.
//

#ifndef ALGOS_ACTIONBUS_H
#define ALGOS_ACTIONBUS_H

#include "IObservable.h"
#include <vector>

struct Subscriber {
    IObservable *sub;
    int type;
};

class ActionBus {
public:
    void subscribe(IObservable *sub, int type);
    void unsubscribe(IObservable *sub, int type);

    void dispatch(int type, const Action& action);

private:
    std::vector<Subscriber> subscribers;
};


#endif //ALGOS_ACTIONBUS_H
