#include "EventInfo.h"
#include "EventReportModels.h"

class EventController {
private:
    EventInfo info;
    IEventDeleteReporterModel *event_canceler;
    IEventCreateReporterModel *event_creator;
    IEventParticipateReporterModel *event_participate;
    IEventLeaveReporterModel *event_leave;
public:
    bool participate(size_t event_id);
    bool cancelParticipation(size_t event_id);
    void deleteEvent(size_t event_id);
    void createEvent();
}