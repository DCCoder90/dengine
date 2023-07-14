#ifndef DENGINE_UI_H
#define DENGINE_UI_H

#include <string>
#include <vector>
#include "UIWindow.h"

namespace dengine {
/**
* @brief Time is used to help manage gametime, refresh rates, ticks and more
*/
    class UI {
    public:
        UI();

        /**
         * @brief Load the UI
         */
        void Load();

        /**
         * @brief Render the UI
         */
        void Render();

        void Push(UIWindow* window);
        void Pop();

    private:
        std::vector<UIWindow*> windows;
    };
}
#endif //DENGINE_UI_H
