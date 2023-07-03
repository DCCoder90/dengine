#ifndef DENGINE_INPUTCONTROLLER_H
#define DENGINE_INPUTCONTROLLER_H

#include <SDL.h>
#include "../System/Component.h"

namespace dengine {
    class InputController : public Component {
    public:
        InputController(GameObject &parent);

        /**
     * Keyboard key states
     */
        const Uint8 *keystates;

        /**
     * Runs every frame, managing actions based upon current keystates
     */
        void Update();
    };
}

#endif //DENGINE_INPUTCONTROLLER_H
