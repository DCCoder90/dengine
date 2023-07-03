#ifndef SDL_LEARN_GAMEOBJECT_H
#define SDL_LEARN_GAMEOBJECT_H


#include <string>
#include <vector>
#include<bits/stdc++.h>
#include <SDL_rect.h>
#include "../Universal.h"

namespace dengine {
    class Component;

/**
 * @brief A base object for a game
 * The gameobject can be considered the most basic building block of a game.  Everything in a game is considered a gameobject
 * and it's functionality are determined by it's Components
 */
    class GameObject {
    public:
        GameObject(std::string objectName);

        /**
    * @brief Returns the object's name
         * @see name
    */
        std::string GetName();

        /**
    * @brief Adds a component to the GameObject
         * @param component The component to add to the object
         * @see components
    */
        void AddComponent(Component *component);

        /**
    * @brief Removes a component from the GameObject
         * @param component The component to remove
         * @see components
    */
        void RemoveComponent(Component *component);


        bool HasComponent(std::string name);

        /**
         * @brief Called on object instantiation
         */
        virtual void Start();

        /**
    * @brief Runs every frame performing any required logic
    */
        virtual void Update();

        /**
    * @brief Performs render on all attached components
    */
        virtual void Render();

        /**
    * @brief A rect denoting the object's position in space.
    */
        SDL_Rect box;

        void SetPos(float xPos, float yPos);

    private:
        /**
    * @brief A vector containing any components that may be on the GameObject
    */
        std::vector<class Component *> components;
        /**
    * @brief A string containing the object name.
    */
        std::string name;
    };
}

#endif //SDL_LEARN_GAMEOBJECT_H
