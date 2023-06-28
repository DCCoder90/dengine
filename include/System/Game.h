//
// Created by ernes on 6/17/2023.
//

#ifndef SDL_LEARN_GAME_H
#define SDL_LEARN_GAME_H

#include <stdio.h>
#include <SDL.h>
#include "../Player/Player.h"
#include "Time.h"
#include <string>
#include "../Player/Enemy.h"
#include <SDL_image.h>
#include <vector>
#include "Sprite.h"
#include "GameStates.h"


class Game {
public:
    Game();

    void loop();

    void handleEvents();

    void update();

    void draw();

    void cleanup();

private:
    SDL_Window *window = NULL;
    SDL_Renderer *renderer;
    bool isRunning = true;
    Time time;

    class Player *player;

    std::vector<class Enemy *> enemies;
    //int gameState = GAMESTATES::Playing;
    GameState gameState;
};

#endif //SDL_LEARN_GAME_H