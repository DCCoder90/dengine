//
// Created by ernes on 6/17/2023.
//

#include "../../include/System/Game.h"

Game* Game::instance;

Game::Game() {
    isRunning = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
        isRunning = false;
    }

    if (IMG_Init(IMG_INIT_PNG) < 0) {
        printf("SDL could not initialize images! SDL_ERROR: %s\n", IMG_GetError());
        isRunning = false;
    }

    window = SDL_CreateWindow("Main Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
                              SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
        printf("Renderer not initialize! SDL_ERROR: %s\n", SDL_GetError());
        isRunning = false;
    }

    if (window == NULL) {
        printf("Window could not be created! SDL_ERROR: %s\n", SDL_GetError());
        isRunning = false;
    }

    GameState::GetInstance().setGameState(GAMESTATES::Playing);
}

Game& Game::GetInstance() {
    if (instance == nullptr) {
        instance = new Game();
    }
    return *instance;
}

SDL_Renderer* Game::GetRenderer() {
    return renderer;
}

GameLevel& Game::GetCurrentState() {
    if (stateStack.empty()) {
        throw std::runtime_error("State stack is empty, can't get current state");
    }

    return *(stateStack.top().get());
}

void Game::Push(GameLevel* state) {
    storedState = state;
}

void Game::loop() {
    if (storedState == nullptr) {
        throw std::runtime_error("Can not start Game without an initial state");
    }

    stateStack.emplace(storedState);
    storedState = nullptr;

    GetCurrentState().Start();

    while (!(stateStack.empty())|| GameState::GetInstance().getGameState() != GAMESTATES::Quit) {
        Time::GetInstance().StartTick();
        auto& topState = stateStack.top();

        if (storedState != nullptr) {
            if (!stateStack.empty()) {
                auto& pauseState = stateStack.top();
                pauseState->Pause();
            }
            stateStack.emplace(storedState);
            storedState->Start();
            storedState = nullptr;
        }

        if (stateStack.empty()) {
            break;
        }

        auto& state = stateStack.top();

        Time::GetInstance().EndTick();
        state->Update();
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }

    while (!stateStack.empty()) {
        stateStack.pop();
    }

    cleanup();
}

void Game::cleanup() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
