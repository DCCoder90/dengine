#ifndef DENGINE_ROUNDEDBOX_H
#define DENGINE_ROUNDEDBOX_H
#include "../UIComponent.h"
#include <SDL.h>
#include <cmath>

namespace dengine {
    /**
     * @brief A rectangle with rounded corners
     */
    class RoundedBox : public UIComponent {
    public:
        /**
         * @brief Initializes a rectangle with rounded corners
         * @param rect The rectangle
         * @param width
         * @param cornerRadius The radius of the corners
         */
        void Setup(SDL_Rect rect, double width, int cornerRadius);

        void Render() override;

    private:
        SDL_Rect boxRect;
        int cornerR;
        double borderWidth;
    };
}
#endif //DENGINE_ROUNDEDBOX_H
