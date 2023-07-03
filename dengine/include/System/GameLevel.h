#ifndef DENGINE_GAMELEVEL_H
#define DENGINE_GAMELEVEL_H


#include "GameObject.h"
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>

namespace dengine {
/**
 * @brief A level of the game
 * This is the base level for individual game development.  A game level could be a title screen, a traditional level for the game
 * or more.  This is where all the objects will live and is what will act as an interface between the GameObjects and the Game
 * @see Game
 * @see GameObject
 */
    class GameLevel {
    public:
        /**
     * @brief Creates a new gamelevel
     */
        GameLevel();

        /**
         * @brief Cleans up and removes any memory allocated by GameLevel
         */
        virtual ~GameLevel();

        /**
     * @brief Used for loading assets into memory
     */
        virtual void Load() = 0;

        /**
     * @brief Used for performing logic updates
     */
        virtual void Update() = 0;

        /**
     * @brief Used for rendering graphics, text and more
     */
        virtual void Render() = 0;

        /**
     * @brief Called at instantiation
     */
        virtual void Start() = 0;

        /**
     * @brief Pauses the game
     */
        virtual void Pause() = 0;

        /**
         * @brief Resumes the game
         */
        virtual void Resume() = 0;

        /**
         * @brief Adds an object to the level
         */
        virtual std::weak_ptr <GameObject> AddObject(GameObject *go);

        /**
         * @brief Retrieves a pointer to the object from the level
         */
        virtual std::weak_ptr <GameObject> GetObject(GameObject *go);

        /**
     * @brief Retrieves an object from the level based on if it has a component or not
     */
        virtual std::weak_ptr <GameObject> GetObjectByComponent(std::string componentName);

    protected:
        /**
     * @brief Calls the start method on any registered objects
     */
        void StartObjects();

        /**
     * @brief Calls the Update method on any registered objects
     */
        virtual void UpdateObjects();

        /**
     * @brief Calls the Render method on any registered objects
     */
        virtual void RenderObjects();

        /**
     * @brief Is true if Start has already ran
         * @see Start
     */
        bool started;
        std::vector <std::shared_ptr<GameObject>> objects;
        std::vector <std::shared_ptr<GameObject>> newObjects;
    };
}

#endif //DENGINE_GAMELEVEL_H