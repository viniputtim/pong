# ifndef LOADING_HPP
# define LOADING_HPP


# include <memory>
# include <raylib.h>
# include "game.hpp"
# include "scene.hpp"
# include "scheduled_event.hpp"


class Loading : public Scene
{
private:
    std::shared_ptr<ScheduledEvent> scheduled_event;
    Texture2D raylib_logo {LoadTexture("../assets/graphics/raylib_logo.png")};

public:
    Loading(Game *game);
    ~Loading();
    void check_events() override;
    void update() override;
    void draw() override;
};


# endif
