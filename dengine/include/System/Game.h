#ifndef DENGINE_GAME_H
#define DENGINE_GAME_H

#include <stdio.h>
#include <SDL.h>
#include "Time.h"
#include <string>
#include <SDL_image.h>
#include <vector>
#include <memory>
#include <stack>
#include <SDL_ttf.h>
#include "GameStates.h"
#include "GameLevel.h"
#include "../Utils/Serializer.h"
#include "../Universal.h"
#include "../UI/UI.h"
#include "EventSystem.h"

using namespace dengine_UI;

namespace dengine {
/**
 * A Game is the most bottom level of the game engine.  The game controls the game loop, managing state, and others.  For
 * individual developers there shouldn't be a need to inherit from or overwrite this class.
 * @brief The base level of the engine
 */
    class Game {
    public:
        Game();

        /**
         * @brief Retrieves the current GameLevel
         */
        GameLevel &GetCurrentState();

        /**
         * @brief Pushes a new GameLevel onto the internal stack
         */
        void Push(GameLevel *state);
        /**
         * @brief Pops a level from the internal stack
         */
        void Pop();

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
        static Game &GetInstance();

        /**
         * Returns the current game's renderer
         */
        SDL_Renderer *GetRenderer();

        /**
         * A pointer to the game's window
         */
        SDL_Window *window = NULL;

        template<typename T>
        /**
         * Saves the current game state to a file
         * @param serializer The serializer to use for saving
         * @return True if success
         */
        bool SaveState(Serializer<T>* serializer);

        template<typename T>
        /**
         * Loads a state from a file and sets the games state
         * @param serializer The serializer to use for loading
         * @return True if success
         */
        bool LoadState(Serializer<T>* serializer);

        /**
         * Retrieves a pointer to the system UI
         * @return The UI
         * @see UI.h
         */
        UI *GetUI();

        /**
         * Retrieves a pointer to the Event System
         * @return The Event System
         * @see EventSystem.h
         */
        EventSystem *GetEventSystem();
    private:
        UI *ui;
        EventSystem *eventSystem;
        SDL_Renderer *renderer;
        std::stack <std::unique_ptr<GameLevel>> stateStack;
        GameLevel *storedState;
        static Game *instance;
    };

    template<typename T>
    bool Game::SaveState(Serializer<T>* serializer) {
        T* level = dynamic_cast<T*>(&GetCurrentState());
        return serializer->saveToFile(level);
    }

    template<typename T>
    bool Game::LoadState(Serializer<T>* serializer) {
        T level = serializer->loadFromFile();
        Pop();
        Push(new T(level));
        return true;
    }
}
#endif //DENGINE_GAME_H