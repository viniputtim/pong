# ifndef WIN_HPP
# define WIN_HPP


# include <raylib.h>
# include "game.hpp"
# include "scene.hpp"


class Win : public Scene
{
private:
    const char *text {"You Won!"};
    int text_x;
    int text_y;
    int font_size {80};
    int spacing {2};
    Color text_color {GREEN};

public:
    Win(Game *game);
    ~Win();
    void check_events() override;
    void update() override;
    void draw() override;
};


# endif
