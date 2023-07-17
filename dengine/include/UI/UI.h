#ifndef DENGINE_UI_H
#define DENGINE_UI_H

#include <string>
#include <vector>
#include "UIWindow.h"

namespace dengine {
/**
* @brief Used to manage the UI of a game
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

        /**
         * Push a UI window onto the stack
         * @param window The window to add to the stack
         */
        void Push(UIWindow* window);
        /**
         * @brief Pop a UI window from the stack
         */
        void Pop();

    private:
        std::vector<UIWindow*> windows;
    };
}
#endif //DENGINE_UI_H
