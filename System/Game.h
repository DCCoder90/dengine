//
// Created by ernes on 6/17/2023.
//

#ifndef SDL_LEARN_GAME_H
#define SDL_LEARN_GAME_H
#include <stdio.h>
#include <sdl.h>
#include "../Player/Player.h"
#include "Time.h"
#include <string>
#include "../Player/Enemy.h"
#include <SDL_image.h>
#include <vector>
#include "Sprite.h"

enum GAMESTATES{
    Playing,
    Gameover
};

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
    class Player* player;
    std::vector<class Enemy*> enemies;
    int gameState = GAMESTATES::Playing;
};

#endif //SDL_LEARN_GAME_H