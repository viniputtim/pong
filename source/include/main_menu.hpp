# ifndef MAIN_MENU_HPP
# define MAIN_MENU_HPP


# include <raylib.h>
# include "game.hpp"
# include "scene.hpp"


class MainMenu : public Scene
{
private:
    const char *title_text {"Game"};
    int title_font_size {80};
    Color title_color {BLACK};
    const char *play_button_text {"Play"};
    int play_button_font_size {40};
    Color play_button_color {BLACK};
    Color play_button_hover_color {DARKGRAY};
    const char *exit_button_text {"Exit"};
    int exit_button_font_size {40};
    Color exit_button_color {RED};
    Color exit_button_hover_color {PINK};
    int spacing {2};

    Vector2 calculate_title_position();
    Vector2 get_title_size();
    bool is_mouse_hover_play_button();
    Vector2 calculate_play_button_position();
    Vector2 get_play_button_size();
    bool is_mouse_hover_exit_button();
    Vector2 calculate_exit_button_position();
    Vector2 get_exit_button_size();

public:
    MainMenu(Game *game);
    ~MainMenu();
    void check_events() override;
    void update() override;
    void draw() override;
};


# endif
