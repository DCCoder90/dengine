//
// Created by ernes on 7/16/2023.
//

#ifndef DENGINE_HOLLOWRECT_H
#define DENGINE_HOLLOWRECT_H
#include "../UIComponent.h"
#include <SDL.h>
#include <cmath>
#include "../../System/Game.h"


namespace dengine {
    /**
     * @brief A rectangle with a hollow or transparent center
     */
    class HollowRect : public UIComponent {
    public:
        /**
         * Initializes a rectangle with a hollow center
         * @param rect The rectangle to display
         * @param width The width of the sides
         */
        void Setup(SDL_Rect rect, int width);

        void Render() override;

    private:
        SDL_Rect boxRect;
        int borderWidth;
    };
}


#endif //DENGINE_HOLLOWRECT_H
