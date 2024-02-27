# include <raylib.h>
# include "game.hpp"


int main(int argc, char *argv[])
{
    InitWindow(0, 0, "Game");
    InitAudioDevice();
    ToggleFullscreen();
    SetMasterVolume(0.75);
    Game game;
    game.run();
    CloseWindow();
    CloseAudioDevice();
}
