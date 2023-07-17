#ifndef DENGINE_FILLEDCIRCLE_H
#define DENGINE_FILLEDCIRCLE_H
#include "../UIComponent.h"
#include <SDL.h>
#include <cmath>
#include "../../System/Game.h"
#include "../../Vec2.h"

using namespace dengine;

namespace dengine_UI {
    /**
     * @brief A filled circle
     */
    class FilledCircle : public UIComponent{
    public:
        /**
         * Initializes a filled circle to be displayed on screen
         * @param center A vec2 denoting the center of the circle
         * @param radius The radius of the circle in pixels
         */
        void Setup(Vec2 center, int radius);

        void Render() override;

    private:
        Vec2 centerPoint;
        int r;
    };
}

#endif //DENGINE_FILLEDCIRCLE_H
