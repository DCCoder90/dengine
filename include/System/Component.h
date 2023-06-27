//
// Created by ernes on 6/24/2023.
//

#ifndef SDL_LEARN_COMPONENT_H
#define SDL_LEARN_COMPONENT_H

#include <string>

/**
* A component adds aditional functionality to a Gameobject without being a defining factor of the object
*/
class Component {
public:
    /**
 *  @param componentName A string denoting the name of the component.  This should be unique
 */
    Component(std::string componentName);
    /**
* Returns the component's name
 * @see name
*/
    std::string GetName();
    /**
* Runs every frame performing any required logic
 * @see components
*/
    virtual void Update();
private:
    std::string name;
};


#endif //SDL_LEARN_COMPONENT_H
