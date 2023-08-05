#define SDL_MAIN_HANDLED
#include <System/Game.h>
#include "TitleScreen/TitleScreen.h"
#include <Utils/NanoLog.h>

int main(int argc, char *argv[]) {
    nanolog::initialize(nanolog::GuaranteedLogger(), "./", "logfile", 3);
    Game& game = Game::GetInstance();
    DemoGame::TitleScreen* baseLevel = new DemoGame::TitleScreen();
    game.Push(baseLevel);
    game.loop();
    return 0;
}
