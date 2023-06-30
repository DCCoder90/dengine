#define SDL_MAIN_HANDLED

#include "include/System/Game.h"
#include "Game/BaseLevel.h"

Game game;

int main(int argc, char *argv[]) {
    Game& game = Game::GetInstance();
    BaseLevel* baseLevel = new BaseLevel();
    game.Push(baseLevel);
    game.loop();
    return 0;
}