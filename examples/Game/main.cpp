#include <System/Game.h>
#include "BaseLevel.h"
#include <Utils/NanoLog.h>

int main() {
    nanolog::initialize(nanolog::GuaranteedLogger(), "./", "logfile", 3);
    Game& game = Game::GetInstance();
    DemoGame::BaseLevel* baseLevel = new DemoGame::BaseLevel();
    game.Push(baseLevel);
    game.loop();
    return 0;
}
