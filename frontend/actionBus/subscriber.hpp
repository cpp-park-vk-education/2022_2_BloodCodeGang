#include <iostream>
#include "frontend/actionBus/IObservable.hpp"

class Subscriber{
public:
    IObservable *subscriber;
    int type;
}