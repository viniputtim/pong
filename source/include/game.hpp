# ifndef GAME_HPP
# define GAME_HPP


# include <map>
# include <memory>
# include <string>
# include <vector>
# include <raylib.h>
# include "level_one.hpp"
# include "loading.hpp"
# include "lose.hpp"
# include "main_menu.hpp"
# include "scene.hpp"
# include "scheduled_event.hpp"
# include "win.hpp"


class Game
{
private:
    bool running {true};
    bool show_fps_counter {false};
    std::shared_ptr<Scene> scene;
    std::map<std::string, std::shared_ptr<Scene>> scenes;
    std::vector<std::shared_ptr<ScheduledEvent>> scheduled_events;

    void check_scheduled_events();
    void check_events();
    void update();
    void draw();

public:
    Game();
    ~Game() {};
    void run();
    void quit();
    void set_scene(const char *scene_name);
    void destroy_scene(const char *scene_name);


    template<typename Function, typename ...Args>
    std::shared_ptr<ScheduledEvent> set_timeout(float seconds, Function function, Args ...args)
    {
        std::shared_ptr<ScheduledEvent> scheduled_event = std::make_shared<ScheduledEvent> (
            false, seconds, function, args...
        );

        this->scheduled_events.push_back(scheduled_event);

        return scheduled_event;
    }


    template<typename Function, typename ...Args>
    std::shared_ptr<ScheduledEvent> set_interval(float seconds, Function function, Args ...args)
    {
        std::shared_ptr<ScheduledEvent> scheduled_event = std::make_shared<ScheduledEvent> (
            true, seconds, function, args...
        );

        this->scheduled_events.push_back(scheduled_event);

        return scheduled_event;
    }
};


# endif
