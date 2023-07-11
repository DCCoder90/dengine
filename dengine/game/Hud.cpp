//
// Created by ernes on 7/6/2023.
//

#include "Hud.h"

using namespace DemoGame;
using namespace dengine;

Hud::Hud(dengine::GameObject &parent) : Component(parent) {
    document = Game::GetInstance().GetUIContext() ->LoadDocument("./assets/ui/hud.rml");
}

void Hud::Render() {

}

Hud::~Hud(){
    document->Close();
}