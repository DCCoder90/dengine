#ifndef SDL_LEARN_GAME_H
#define SDL_LEARN_GAME_H

#include <stdio.h>
#include <SDL.h>
#include "Time.h"
#include <string>
#include <SDL_image.h>
#include <vector>
#include <memory>
#include <stack>
#include "GameStates.h"
#include "GameLevel.h"
#include "../Universal.h"


class Game {
public:
    Game();

    GameLevel& GetCurrentState();
    void Push(GameLevel* state);

    void loop();

    void handleEvents();

    void update();

    void draw();

    void cleanup();
    static Game& GetInstance();
    SDL_Renderer* GetRenderer();
    SDL_Window *window = NULL;

private:
    SDL_Renderer *renderer;

    std::stack<std::unique_ptr<GameLevel>> stateStack;
    GameLevel* storedState;
    static Game* instance;

    bool isRunning = true;
};

#endif //SDL_LEARN_GAME_H