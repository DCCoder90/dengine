#ifndef DENGINE_GAMEOBJECT_H
#define DENGINE_GAMEOBJECT_H


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

        /**
         * Checks if the gameobject has a component with the specified name
         * @brief Does it have a component?
         * @param name The name of the component to check
         * @return True if this gameobject has a component with the name name.
         */
        bool HasComponent(std::string name);

        /**
         * @brief Called on object instantiation
         */
        virtual void Start();

        /**
         * Notify the gameobject and any components of a collision
         * @param other The other gameobject being collided with
         */
        virtual void NotifyCollision(GameObject& other);

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

        /**
         * Set the position of the game object
         * @brief Set position
         * @param xPos X position
         * @param yPos Y position
         */
        void SetPos(float xPos, float yPos);

        /**
         * @brief Get a reference to a component
         * @param name Name of the component to get
         * @return A weak pointer to the component on the gameobject
         * @code
         * if(gameObject->HasComponent("Collider")){
         *   Component* collider = gameObject->GetComponentByName("Collider").lock();
         * }
         * @endcode
         */
        std::weak_ptr<Component> GetComponentByName(std::string name);

        /**
        * @brief Add a tag to the game object
        */
        void AddTag(std::string tag){
            auto it = std::find(tags.begin(), tags.end(), tag);
            if(it == tags.end()) {
                tags.push_back(tag);
            }
        }

        /**
    * @brief Check if game object has a tag
         * @return True if the game object has the tag
    */
        bool HasTag(std::string tag){
            auto it = std::find(tags.begin(), tags.end(), tag);
            return it == tags.end();
        }

        /**
        * @brief Remove tag from game object
        */
        void RemoveTag(std::string tag){
            auto it = std::find(tags.begin(), tags.end(), tag);
            if(it == tags.end()) {
                tags.erase(std::remove(tags.begin(),tags.end(),tag),tags.end());
            }
        }

    private:
        /**
    * @brief A vector containing any components that may be on the GameObject
    */
        std::vector<class Component *> components;
        /**
    * @brief A string containing the object name.
    */
        std::string name;
        std::vector<std::string> tags;
    };
}

#endif //DENGINE_GAMEOBJECT_H
