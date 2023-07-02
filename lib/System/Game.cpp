#include "../../include/System/Game.h"

Game* Game::instance;

Game::Game() {
    if (instance == nullptr) {
        instance = this;
    } else {
        throw std::logic_error("Game constructor called when an instance is already created");
    }
    isRunning = true;
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
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
    LOG_INFO << "Created game";
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

    while (!(stateStack.empty())&& GameState::GetInstance().getGameState() != GAMESTATES::Quit) {
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

        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
                GameState::GetInstance().setGameState(GAMESTATES::Quit);
            }
        }

        //TODO: Change this to be an end game screen
        //TODO: Add a way to change levels
        //TODO: Move this to a GameLevel
        if(GameState::GetInstance().getGameState() == GAMESTATES::Gameover){
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
            Time::GetInstance().EndTick();
            continue;
        }

        state->Update();
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        state->Render();
        SDL_RenderPresent(renderer);
        Time::GetInstance().EndTick();
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
