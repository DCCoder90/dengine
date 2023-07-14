#include "../../include/UI/UIWindow.h"

using namespace dengine;

void UIWindow::Push(dengine::UIComponent * component) {
    components.push_back(component);
}

void UIWindow::Pop(){
    components.pop_back();
}

void UIWindow::Render() {
    int i;
    for (i = 0; i < components.size(); i++) {
        components[i]->Render();
    }
}