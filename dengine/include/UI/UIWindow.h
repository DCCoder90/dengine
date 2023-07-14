//
// Created by ernes on 7/14/2023.
//

#ifndef DENGINE_UIWINDOW_H
#define DENGINE_UIWINDOW_H
#include <vector>
#include "UIComponent.h"

namespace dengine{
    class UIWindow{
    public:
        void Push(UIComponent *);
        void Pop();
        virtual void Render();

    private:
        std::vector<class UIComponent *> components;
    };
}
#endif //DENGINE_UIWINDOW_H
