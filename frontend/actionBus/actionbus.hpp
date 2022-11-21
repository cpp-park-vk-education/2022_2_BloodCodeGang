#include <iostream>

class ActionBus {
public:
    void subscribe(IObsevable *subscriber, int type);
    void unsubscribe(IObservable *subscriber, int type);
    void dispatch(int type, const Action &action);
}