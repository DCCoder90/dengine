#define SDL_MAIN_HANDLED

#include "include/System/Game.h"

Game game;

int main(int argc, char *argv[]) {
    game.loop();
    return 0;
}