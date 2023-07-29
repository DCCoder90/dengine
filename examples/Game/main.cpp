#define SDL_MAIN_HANDLED
#include <System/Game.h>
#include "Level1/BaseLevel.h"
#include <Utils/NanoLog.h>

int main(int argc, char *argv[]) {
    nanolog::initialize(nanolog::GuaranteedLogger(), "./", "logfile", 3);
    Game& game = Game::GetInstance();
    DemoGame::BaseLevel* baseLevel = new DemoGame::BaseLevel();
    game.Push(baseLevel);
    game.loop();
    return 0;
}
