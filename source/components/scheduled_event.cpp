# include "scheduled_event.hpp"


bool ScheduledEvent::is_marked_for_deletion()
{
    return this->marked_for_deletion;
}


void ScheduledEvent::call()
{
    if (GetTime() >= this->start + this->seconds) {
        this->function();

        if (this->repeat == true) {
            this->start = GetTime();
        } else {
            this->quit();
        }
    }
}


void ScheduledEvent::quit()
{
    this->marked_for_deletion = true;
}
