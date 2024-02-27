# include "game.hpp"


Game::Game()
{
    this->scenes["loading"] = std::make_shared<Loading> (this);
    this->scenes["main menu"] = std::make_shared<MainMenu> (this);
    this->scenes["level one"] = std::make_shared<LevelOne> (this);
    this->scenes["win"] = std::make_shared<Win> (this);
    this->scenes["lose"] = std::make_shared<Lose> (this);

    this->set_scene("loading");
}


void Game::set_scene(const char *scene_name)
{
    this->scene = this->scenes[scene_name];
}


void Game::destroy_scene(const char *scene_name)
{
    auto it {this->scenes.find(scene_name)};

    if (it != this->scenes.end()) {
        this->scenes.erase(it);
    }
}


void Game::run()
{
    while(!WindowShouldClose() && this->running) {
        this->check_scheduled_events();
        this->check_events();
        this->update();
        this->draw();
    }
}


void Game::check_scheduled_events()
{
    for (int i {0}; i < this->scheduled_events.size(); ++i) {
        if (this->scheduled_events[i]->is_marked_for_deletion()) {
            this->scheduled_events.erase(this->scheduled_events.begin() + i);
            --i;
        } else {
            this->scheduled_events[i]->call();
        }
    }
}


void Game::check_events()
{
    if (IsKeyPressed(KEY_TAB)) {
        this->show_fps_counter = !this->show_fps_counter;
    }

    this->scene->check_events();
}


void Game::update()
{
    this->scene->update();
}


void Game::draw()
{
    BeginDrawing();
    this->scene->draw();

    if (this->show_fps_counter) {
        DrawFPS(0, 0);
    }

    EndDrawing();
}


void Game::quit()
{
    this->running = false;
}
