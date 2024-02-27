# include "main_menu.hpp"


MainMenu::MainMenu(Game *game) : Scene(game)
{

}


MainMenu::~MainMenu()
{

}


Vector2 MainMenu::calculate_title_position()
{
    Vector2 title_size {this->get_title_size()};
    Vector2 play_button_position {this->calculate_play_button_position()};

    float x {
        (GetScreenWidth() - title_size.x) / 2
    };
    float y {
        (play_button_position.y - title_size.y) / 2
    };

    return {x, y};
}


Vector2 MainMenu::get_title_size()
{
    return MeasureTextEx(GetFontDefault(), this->title_text, this->title_font_size, this->spacing);
}


bool MainMenu::is_mouse_hover_play_button()
{
    Vector2 play_button_position {this->calculate_play_button_position()};
    Vector2 play_button_size {this->get_play_button_size()};

    return  CheckCollisionPointRec(
        GetMousePosition(),
        {play_button_position.x, play_button_position.y, play_button_size.x, play_button_size.y}
    );
}


Vector2 MainMenu::calculate_play_button_position()
{
    Vector2 play_button_size {this->get_play_button_size()};

    float x {(GetScreenWidth() - play_button_size.x) / 2};
    float y {(GetScreenHeight() - play_button_size.y) / 2};

    return {x, y};
}


Vector2 MainMenu::get_play_button_size()
{
    return MeasureTextEx(GetFontDefault(), this->play_button_text, this->play_button_font_size, this->spacing);
}


bool MainMenu::is_mouse_hover_exit_button()
{
    Vector2 exit_button_position {this->calculate_exit_button_position()};
    Vector2 exit_button_size {this->get_exit_button_size()};

    return  CheckCollisionPointRec(
        GetMousePosition(),
        {exit_button_position.x, exit_button_position.y, exit_button_size.x, exit_button_size.y}
    );
}


Vector2 MainMenu::calculate_exit_button_position()
{
    Vector2 play_button_position {this->calculate_play_button_position()};
    Vector2 play_button_size {this->get_play_button_size()};
    Vector2 exit_button_size {this->get_exit_button_size()};

    float x {(GetScreenWidth() - exit_button_size.x) / 2};
    float y {play_button_position.y + play_button_size.y + exit_button_size.y};

    return {x, y};
}


Vector2 MainMenu::get_exit_button_size()
{
    return MeasureTextEx(GetFontDefault(), this->exit_button_text, this->exit_button_font_size, this->spacing);
}


void MainMenu::check_events()
{
    if (IsMouseButtonReleased(0)) {
        if (this->is_mouse_hover_play_button()) {
            this->game->set_scene("level one");
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        } else if (this->is_mouse_hover_exit_button()) {
            this->game->quit();
        }
    }
}


void MainMenu::update()
{
    bool mouse_hover_any_button {this->is_mouse_hover_play_button() || this->is_mouse_hover_exit_button()};

    SetMouseCursor(mouse_hover_any_button ? MOUSE_CURSOR_POINTING_HAND : MOUSE_CURSOR_DEFAULT);
}


void MainMenu::draw()
{
    Vector2 title_position {this->calculate_title_position()};
    Vector2 play_button_position {this->calculate_play_button_position()};
    Vector2 exit_button_position {this->calculate_exit_button_position()};

    ClearBackground(RAYWHITE);
    DrawText(
        this->title_text, title_position.x, title_position.y, this->title_font_size, this->title_color
    );
    DrawText(
        this->play_button_text, play_button_position.x, play_button_position.y, this->play_button_font_size,
        (this->is_mouse_hover_play_button() ? this->play_button_hover_color : this->play_button_color)
    );
    DrawText(
        this->exit_button_text, exit_button_position.x, exit_button_position.y, this->exit_button_font_size,
        (this->is_mouse_hover_exit_button() ? this->exit_button_hover_color : this->exit_button_color)
    );
}
