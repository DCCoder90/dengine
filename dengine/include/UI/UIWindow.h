//
// Created by ernes on 7/14/2023.
//

#ifndef DENGINE_UIWINDOW_H
#define DENGINE_UIWINDOW_H
#include <vector>
#include "UIComponent.h"

namespace dengine{
    /**
     * @brief A UI window
     * Meant to be a collection of related UIComponents to display at the same time
     * @see UIComponent
     */
    class UIWindow{
    public:
        /**
         * @brief Push a component onto the stack
         */
        void Push(UIComponent *);
        /**
         * @brief Pop a UI element from the stack
         */
        void Pop();
        /**
         * Render all components on the stack
         */
        virtual void Render();

    private:
        std::vector<class UIComponent *> components;
    };
}
#endif //DENGINE_UIWINDOW_H
