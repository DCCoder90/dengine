#include "../../include/UI/UI.h"

using namespace dengine;

UI::UI(){

};

void UI::Render() {
    int i;
    for (i = 0; i < windows.size(); i++) {
        windows[i]->Render();
    }
};

void UI::Load() {

};

void UI::Push(dengine::UIWindow *window) {
    windows.push_back(window);
}

void UI::Pop() {
    windows.pop_back();
}