#include "../../include/UI/UIWindow.h"

using namespace dengine_UI;

void UIWindow::Push(UIComponent * component) {
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

void UIWindow::Update() {
    int i;
    for (i = 0; i < components.size(); i++) {
        components[i]->Update();
    }
}