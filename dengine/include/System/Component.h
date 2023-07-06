#ifndef DENGINE_COMPONENT_H
#define DENGINE_COMPONENT_H

#include "GameObject.h"
#include <string>

namespace dengine {
/**
* A component adds additional functionality to a Gameobject without being a defining factor of the object.  This is an empty class
 * and is meant to be extended upon depending upon the needs of the developer.  For some examples see Sprite, SpriteSheet, or other
 * preexisting components
 * @brief Gameobject component that asssists in adding additional functionality
*/
    class Component{
    public:
        /**
         * @brief Create a new component for a gameobject
     *  @param parent The parent object that this component is on
     */
        Component(GameObject &parent);

        /**
         * Notify component that a collision has occurred
     *  @param other Reference to the object being collided with
     */
        virtual void NotifyCollision(GameObject &other);

        /**
    * @brief Returns the component's name
     * @see name
    */
        std::string GetName();

        /**
         * @brief Start the object
         * To be called by the GameObject's Start method.  This should be called at the beginning of instantiation
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
        std::string name;
    };
}

#endif //DENGINE_COMPONENT_H
