# include "loading.hpp"


Loading::Loading(Game *game) : Scene(game)
{
    this->scheduled_event = this->game->set_timeout(5, [this]() {
        this->game->set_scene("main menu");
        this->game->destroy_scene("loading");
    });
}


Loading::~Loading()
{

}


void Loading::check_events()
{
    if (IsMouseButtonReleased(0)) {
        if (this->scheduled_event != nullptr) {
            this->scheduled_event->quit();
        }

        this->game->set_scene("main menu");
    }
}


void Loading::update()
{

}


void Loading::draw()
{
    int x {(GetScreenWidth() - this->raylib_logo.width) / 2};
    int y {(GetScreenHeight() - this->raylib_logo.height) / 2};

    ClearBackground({RAYWHITE});
    DrawTexture(this->raylib_logo, x, y, WHITE);
}
