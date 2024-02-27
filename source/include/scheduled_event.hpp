# ifndef SCHEDULED_EVENT
# define SCHEDULED_EVENT


# include <functional>
# include <raylib.h>


class ScheduledEvent
{
private:
    bool marked_for_deletion {false};
    bool repeat;
    float start;
    float seconds;
    std::function<void()> function;

public:
    ScheduledEvent() {};
    ~ScheduledEvent() {};
    bool is_marked_for_deletion();
    void call();
    void quit();

    template<typename F, typename ...Args>
    ScheduledEvent(
        bool repeat, float seconds, F function, Args ...args
    )
    {
        this->repeat = repeat;
        this->start = GetTime();
        this->seconds = seconds;
        this->function = [function, args...]() { function(args...); };
    }
};


# endif
