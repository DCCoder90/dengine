#ifndef DENGINE_PROGRESSBARV_H
#define DENGINE_PROGRESSBARV_H
#include <SDL.h>
#include "../UIComponent.h"
#include "../../Vec2.h"

namespace dengine_UI {
    /**
     * @brief A verticle progress bar
     * Variables are:
     * xpos - The x position of the progress bar
     * ypos - The y position of the progress bar
     * completed - The amount completed on a scale of 0 - 100
     */
    class ProgressBarV : public UIComponent {
    public:
        /**
         * @brief Initializes required parameters
         * @param initPos The X,Y coordinates of the bar on the screen
         * @param initAmount The initial value of the progress bar (0)
         */
        void Setup(dengine::Vec2 initPos, int initAmount = 0){
            completed = initAmount;
            position = initPos;
        }
        void Render() override;

        /**
         * @brief Sets the fill color of the progress bar
         * @param color Fill color
         */
        void SetFillColor(SDL_Color color){
            fillColor = color;
        }

        /**
         * @brief Sets the filled progress of the progress bar
         * @param completeAmount Number between 0 and 100
         */
        void SetCompleted(int completeAmount) {
            completed = completeAmount;
        }
    private:
        int completed;
        dengine::Vec2 position;
        SDL_Color fillColor;
    };
}

#endif //DENGINE_PROGRESSBARV_H
