//
// Created by ernes on 6/24/2023.
//

#ifndef SDL_LEARN_COMPONENT_H
#define SDL_LEARN_COMPONENT_H

#include "GameObject.h"
#include <string>

/**
* A component adds aditional functionality to a Gameobject without being a defining factor of the object
*/
class Component {
public:
    /**
 *  @param parent The parent object that this component is on
 */
    Component(GameObject &parent);

    /**
 *  @param other Reference to the object being collided with
 */
    virtual void NotifyCollision(GameObject &other);

    /**
* Returns the component's name
 * @see name
*/
    std::string GetName();

    /**
     * Called on instantiation
     */
    virtual void Start();

    /**
* Runs every frame performing any required logic
 * @see components
*/
    virtual void Update();
    /**
* Used for drawing to screen
* @see components
*/
    virtual void Render();

protected:
    GameObject &parent;
private:
    std::string name;
};


#endif //SDL_LEARN_COMPONENT_H
