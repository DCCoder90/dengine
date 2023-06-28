//
// Created by ernes on 6/24/2023.
//

#ifndef SDL_LEARN_COMPONENT_H
#define SDL_LEARN_COMPONENT_H

#include <string>
#include "GameObject.h"

/**
* A component adds aditional functionality to a Gameobject without being a defining factor of the object
*/
class Component {
public:
    /**
 *  @param componentName A string denoting the name of the component.  This should be unique
 */
    Component(GameObject& parent);
    /**
 *  @param other Reference to the object being collided with
 */
    virtual void NotifyCollision(GameObject& other);
    /**
* Returns the component's name
 * @see name
*/
    std::string GetName();

    /**
     * Called on instantiation
     */
    void Start();
    /**
* Runs every frame performing any required logic
 * @see components
*/
    virtual void Update();
protected:
    GameObject& parent;
private:
    std::string name;
};


#endif //SDL_LEARN_COMPONENT_H
