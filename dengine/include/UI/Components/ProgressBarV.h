#ifndef DENGINE_PROGRESSBARV_H
#define DENGINE_PROGRESSBARV_H
#include "../UIComponent.h"
namespace dengine_UI {
    /**
     * @brief A verticle progress bar
     * Variables are:
     * xpos - The x position of the progress bar
     * ypos - The y position of the progress bar
     * completed - The amount completed on a scale of 0 - 100
     */
    class ProgressBarV : public UIComponent {
        void Render() override;
    };
}

#endif //DENGINE_PROGRESSBARV_H
