#ifndef DENGINE_PROGRESSBARV_H
#define DENGINE_PROGRESSBARV_H
#include "../UIComponent.h"
namespace dengine {
    /**
     * @brief A horizontal progress bar
     * Variables are:
     * xpos - The x position of the progress bar
     * ypos - The y position of the progress bar
     * completed - The amount completed on a scale of 0 - 100
     */
    class ProgressBarH : public UIComponent {
        void Render() override;
    };
}


#endif //DENGINE_PROGRESSBARV_H
