#define SDL_MAIN_HANDLED
#define DEBUG
#include "include/System/Game.h"
#include "Game/BaseLevel.h"
#include "include/Universal.h"

int main(int argc, char *argv[]) {
    nanolog::initialize(nanolog::GuaranteedLogger(), "./", "logfile", 3);
    Game& game = Game::GetInstance();
    BaseLevel* baseLevel = new BaseLevel();
    game.Push(baseLevel);
    game.loop();
    return 0;
}