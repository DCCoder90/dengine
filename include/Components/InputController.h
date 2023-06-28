//
// Created by ernes on 6/24/2023.
//

#ifndef SDL_LEARN_INPUTCONTROLLER_H
#define SDL_LEARN_INPUTCONTROLLER_H
#include <SDL.h>
#include "../System/Component.h"

class InputController: public Component {
public:
    InputController(GameObject& parent);
    /**
 * Keyboard key states
 */
    const Uint8 *keystates;
    /**
 * Runs every frame, managing actions based upon current keystates
 */
    void Update();
};


#endif //SDL_LEARN_INPUTCONTROLLER_H
