# include "lose.hpp"


Lose::Lose(Game *game) : Scene(game)
{

}


Lose::~Lose()
{

}


void Lose::check_events()
{

}


void Lose::update()
{
    Vector2 text_size {MeasureTextEx(GetFontDefault(), this->text, this->font_size, this->spacing)};

    this->text_x = (GetScreenWidth() - text_size.x) / 2;
    this->text_y = (GetScreenHeight() - text_size.y) / 2;
}


void Lose::draw()
{
    ClearBackground(RAYWHITE);
    DrawText(this->text, this->text_x, this->text_y, this->font_size, this->text_color);
}
