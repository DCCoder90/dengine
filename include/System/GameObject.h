#ifndef SDL_LEARN_GAMEOBJECT_H
#define SDL_LEARN_GAMEOBJECT_H


#include <string>
#include <vector>
#include<bits/stdc++.h>
#include <SDL_rect.h>
#include "../Universal.h"

class Component;  //Forward declaration to fix circular dependency
class GameObject {
public:
    GameObject(std::string objectName);

    /**
* Returns the object's name
     * @see name
*/
    std::string GetName();

    /**
* Adds a component to the GameObject
     * @param component The component to add to the object
     * @see components
*/
    void AddComponent(Component *component);

    /**
* Removes a component from the GameObject
     * @param component The component to remove
     * @see components
*/
    void RemoveComponent(Component *component);

    bool HasComponent(std::string name);

    /**
     * Called on object instantiation
     */
    virtual void Start();

    /**
* Runs every frame performing any required logic
*/
    virtual void Update();
    /**
* Performs render on all attached components
*/
    virtual void Render();

    /**
* A rect denoting the object's position in space.
*/
    SDL_Rect box;

    void SetPos(float xPos, float yPos);
private:
    /**
* A vector containing any components that may be on the GameObject
*/
    std::vector<class Component *> components;
    /**
* A string containing the object name.
*/
    std::string name;
};


#endif //SDL_LEARN_GAMEOBJECT_H
