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

/**
 * @brief The base level of the engine
 * A Game is the most bottom level of the game engine.  The game controls the game loop, managing state, and others.  For
 * individual developers there shouldn't be a need to inherit from or overwrite this class.
 */
class Game {
public:
    Game();

    /**
     * @brief Retrieves the current GameLevel
     */
    GameLevel& GetCurrentState();
    /**
     * @brief Pushes a new GameLevel onto the internal stack
     */
    void Push(GameLevel* state);

    /**
     * @brief The game loop
     */
    void loop();

    /**
     * Frees up any allocated resources
     */
    void cleanup();
    /**
     * Returns an instance of the current game
     */
    static Game& GetInstance();
    /**
     * Returns the current game's renderer
     */
    SDL_Renderer* GetRenderer();
    /**
     * A pointer to the game's window
     */
    SDL_Window *window = NULL;

private:
    SDL_Renderer *renderer;
    std::stack<std::unique_ptr<GameLevel>> stateStack;
    GameLevel* storedState;
    static Game* instance;
};

#endif //SDL_LEARN_GAME_H