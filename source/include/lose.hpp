# ifndef LOSE_HPP
# define LOSE_HPP


# include <memory>
# include <raylib.h>
# include "game.hpp"
# include "scene.hpp"
# include "scheduled_event.hpp"


class Lose : public Scene
{
private:
    const char *text {"You Lose!"};
    int text_x;
    int text_y;
    int font_size {80};
    int spacing {2};
    Color text_color {RED};

public:
    Lose(Game *game);
    ~Lose();
    void check_events() override;
    void update() override;
    void draw() override;
};


# endif
