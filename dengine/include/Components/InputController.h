#ifndef DENGINE_INPUTCONTROLLER_H
#define DENGINE_INPUTCONTROLLER_H

#include <SDL.h>
#include "../System/Component.h"

namespace dengine {
    /**
     * @brief An input controller
     * @deprecated Marking this as deprecated as I haven't found a helpful way of integrating this component with
     * the rest of the system.  If I find a way later I'll remove this indicator, but until then don't rely on it being
     * here in the future.
     */
    class InputController : public Component {
    public:
        InputController(GameObject &parent);

        /**
         * @brief Keyboard key states
         */
        const Uint8 *keystates;

        /**
        * Runs every frame, managing actions based upon current keystates
         * @brief Update function
        */
        void Update();
    };
}

#endif //DENGINE_INPUTCONTROLLER_H
