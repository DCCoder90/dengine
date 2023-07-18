#ifndef DENGINE_PROGRESSBARV_H
#define DENGINE_PROGRESSBARV_H
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
        void Setup(dengine::Vec2 initPos, int initAmount = 0){
            completed = initAmount;
            position = initPos;
        }
        void Render() override;
        void SetCompleted(int completeAmount) {
            completed = completeAmount;
        }
    private:
        int completed;
        dengine::Vec2 position;
    };
}

#endif //DENGINE_PROGRESSBARV_H
