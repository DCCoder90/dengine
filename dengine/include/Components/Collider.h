#ifndef DENGINE_COLLIDER_H
#define DENGINE_COLLIDER_H


#include <SDL_rect.h>
#include "../System/Component.h"
#include "../Vec2.h"

namespace dengine {
/**
* @brief Colliders are used to determine collisions between objects in the world's space
*/
    class Collider : public Component {
        Collider(GameObject &associated, Vec2 scale = {1, 1}, Vec2 offset = {0, 0});

        /**
        * @brief A rect denoting the collider's position in space.
        */
        SDL_Rect box;

        void Update() override;

    private:
        /**
    * @brief The scale of the collider
    */
        Vec2 scale;
        /**
    * @brief The collider's offset from it's parent object
    */
        Vec2 offset;
    };
}

#endif //DENGINE_COLLIDER_H
