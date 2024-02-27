# ifndef LELVEL_ONE_HPP
# define LELVEL_ONE_HPP


# include <array>
# include <memory>
# include <raylib.h>
# include "game.hpp"
# include "scene.hpp"
# include "scheduled_event.hpp"


struct Score {
    int a {0};
    int b {0};
    int max {10};
    int x {0};
    int y {0};
    const char *text;
    int font_size {80};
    Color color {WHITE};
};


struct Player
{
    Rectangle rect {0, 0, 25, 100};
    Color color {WHITE};
    int movement {0};
    int speed {550};
};


struct Ball
{
    float radius {25};
    Color color {WHITE};
    Vector2 center {0, 0};
    Vector2 movement {0, 0};
    int speed {600};

};


class LevelOne : public Scene
{
private:
    std::shared_ptr<ScheduledEvent> scheduled_event;
    Score score;
    std::array<Player, 2> players;
    Ball ball;

    void center_ball();

public:
    LevelOne(Game *game);
    ~LevelOne();
    void check_events() override;
    void update() override;
    void draw() override;
};


# endif
