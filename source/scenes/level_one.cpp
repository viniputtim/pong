# include "level_one.hpp"


LevelOne::LevelOne(Game *game) : Scene(game)
{
    this->scheduled_event = this->game->set_interval(0.1, [this]() {
        this->players[1].movement = (
            this->ball.center.y > this->players[1].rect.y + this->players[1].rect.height / 2
        ) ? 1 : -1;
    });

    this->players[1].rect.x = GetScreenWidth() - this->players[1].rect.width;

    for (Player &player : this->players) {
        player.rect.y = GetRandomValue(0, GetScreenHeight() - player.rect.height);
    }

    this->center_ball();
}


LevelOne::~LevelOne()
{

}


void LevelOne::center_ball()
{
    float ball_x {GetScreenWidth() / 2 - this->ball.radius};
    float ball_y {GetScreenHeight() / 2 - this->ball.radius};
    this->ball.center = {ball_x, ball_y};
    this->ball.movement.x = GetRandomValue(0, 1) ? 1 : -1;
    this->ball.movement.y = GetRandomValue(0, 1) ? 1 : -1;
}


void LevelOne::check_events()
{
    this->players[0].movement = static_cast<int> (IsKeyDown(KEY_DOWN)) -
        static_cast<int> (IsKeyDown(KEY_UP));
}


void LevelOne::update()
{
    if (this->score.a == this->score.max || this->score.b == this->score.max) {
        if (this->score.a == this->score.max) {
            this->game->set_scene("win");
        } else {
            this->game->set_scene("lose");
        }

        if (this->scheduled_event != nullptr) {
            this->scheduled_event->quit();
        }
    }

    this->score.text = TextFormat("%i X %i", this->score.a, this->score.b);
    this->score.x = (GetScreenWidth() - MeasureText(this->score.text, this->score.font_size)) / 2;

    for (int i {0}; i < this->players.size(); ++i) {
        this->players[i].rect.y += this->players[i].movement * this->players[i].speed * GetFrameTime();

        if (this->players[i].rect.y < 0) {
            this->players[i].rect.y = 0;
        } else if (this->players[i].rect.y + this->players[i].rect.height > GetScreenHeight()) {
            this->players[i].rect.y = GetScreenHeight() - this->players[i].rect.height;
        }

        if (CheckCollisionCircleRec(
            {this->ball.center.x, this->ball.center.y}, this->ball.radius, this->players[i].rect
        )) {
            this->ball.movement.x = i ? -1 : 1;
        }
    }

    if (
        (this->ball.center.x - this->ball.radius < 0) ||
        (this->ball.center.x + this->ball.radius > GetScreenWidth())
    ) {
        if (this->ball.center.x - this->ball.radius < 0) {
            ++this->score.b;
        } else {
            ++ this->score.a;
        }

        this->center_ball();
    }

    if (
        (this->ball.center.y - this->ball.radius < 0) ||
        (this->ball.center.y + this->ball.radius > GetScreenHeight())
    ) {
        this->ball.movement.y *= -1;
    }

    this->ball.center.x += this->ball.movement.x * this->ball.speed * GetFrameTime();
    this->ball.center.y += this->ball.movement.y * this->ball.speed * GetFrameTime();
}


void LevelOne::draw()
{
    ClearBackground(GREEN);
    DrawCircle(this->ball.center.x, this->ball.center.y, this->ball.radius, this->ball.color);

    for (int i {0}; i < this->players.size(); ++i) {
        DrawRectangleRec(this->players[i].rect, this->players[i].color);
    }

    DrawText(this->score.text, this->score.x, this->score.y, this->score.font_size, this->score.color);
}
