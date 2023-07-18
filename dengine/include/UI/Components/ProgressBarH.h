#ifndef DENGINE_PROGRESSBARV_H
#define DENGINE_PROGRESSBARV_H
#include <SDL.h>
#include "../UIComponent.h"
#include "../../Vec2.h"

namespace dengine_UI {
    /**
     * @brief A horizontal progress bar
     * Variables are:
     * xpos - The x position of the progress bar
     * ypos - The y position of the progress bar
     * completed - The amount completed on a scale of 0 - 100
     */
    class ProgressBarH : public UIComponent {
    public:
        void Setup(dengine::Vec2 initPos, int initAmount = 0){
            completed = initAmount;
            position = initPos;
        }

        void SetFillColor(SDL_Color color){
            fillColor = color;
        }

        void Render() override;
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
