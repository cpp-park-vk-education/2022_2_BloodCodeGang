#include <iostream>
#include "EventInfo.h"

enum Type {NEW_RECOMMENDED_FEED, NEW_MY_FEED, EVENT_CREATE, EVENT_DELETE, EVENT_LEAVE, EVENT_PARTICIPATE};

class Actions {
public:
    Type types;
    std::vector<EventInfo> NewMyFeedInfo(const EventInfo &event) = 0;
    std::vector<EventInfo> NewRecommendedFeedInfo(const EventInfo &event) = 0;
};


class IObservable {
public:
    virtual void update(Action *Action) = 0;
};

class Subscriber {
public:
    IObservable *observable;
    int type;
};

class ActionBus {
private:
    std::vector<Subscriber> subscribers;
public:
    void subscribe(IObservable *subscriber, int type);
    void unsubscribe(IObservable *subscriber, int type);
    void dispatch(int type, const Action &Action);
};