#include "../../include/UI/UI.h"

using namespace dengine_UI;

UI::UI(){

};

void UI::Render() {
    int i;
    for (i = 0; i < windows.size(); i++) {
        windows[i]->Render();
    }
};

void UI::Update() {
    int i;
    for (i = 0; i < windows.size(); i++) {
        windows[i]->Update();
    }
};

void UI::Load() {

};

void UI::Push(UIWindow *window) {
    windows.push_back(window);
}

void UI::Pop() {
    if(!windows.empty()) {
        windows.pop_back();
    }
}