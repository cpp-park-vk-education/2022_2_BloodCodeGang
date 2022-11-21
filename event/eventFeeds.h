#include <iostream>
#include "EventManager.h"
#include "EventReportModels.h"

class IEventFeedModel {
public:
    virtual vector <EventInfo> getEventsInfo() = 0;
};

class RecommendedEventsModel : public IEventFeedModel {
private:
    vector <EventInfo> events;
};

class MeEventsModel : public IEventFeedModel {
private:
    vector <EventInfo> events;
};

class IEventModel {
public:
    virtual bool participate(size_t event_id) = 0;
    virtual bool cancelParticipation(size_t event_id) = 0;
};

class IMyEventModel {
public:
    virtual void deleteEvent(size_t event_id) = 0;
    virtual void createEvent() = 0;
};

class IEventFeedModel {
public:
    virtual vector <EventInfo> getEventFeed() = 0;
    virtual EventInfo getEvent(size_t event_id) = 0;
};


class RecommendedEventFeedModel : public IEventModel, public IEventFeedModel {
private:
    IEventFeedModel *recommended_events;
    actions *ActionBus;
    IEventParticipateReporterModel *event_participate;
    IEventLeaveReporterModel *event_leave;
};

class MyEventFeedModel : public IMyEventModel, public IEventFeedModel {
private:
    IEventFeedModel *my_events;
    actions *ActionBus;
    IEventDeleteReporterModel *event_delete;
    IEventCreateReporterModel *event_create;
};
