#include "EventInfo.h"

class IEventDeleteReporterModel {
public:
    virtual void updateInfo(const EventInfo &event) = 0;
};

class IEventCreateReporterModel {
public:
    virtual void updateInfo(const EventInfo &event) = 0;
};

class IEventParticipateReporterModel {
public:
    virtual void updateInfo(const EventInfo &event) = 0;
};

class IEventLeaveReporterModel {
public:
    virtual void updateInfo(const EventInfo &event) = 0;
};

class EventDeleteReporterModel : public IEventDeleteReporterModel {
private:
    EventInfo event;
};

class EventCreateReporterModel : public IEventCreateReporterModel {
private:
    EventInfo event;
};

class EventParticipateReporterModel : public IEventParticipateReporterModel {
private:
    EventInfo event;
};

class EventLeaveReporterModel : public IEventLeaveReporterModel {
private:
    EventInfo event;
};