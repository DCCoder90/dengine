//
// Created by ernes on 6/29/2023.
//

#include "LeafMan.h"

LeafMan::LeafMan(GameObject &parent) : Component(parent) {
    name = "LeafMan";
}

void LeafMan::Start() {
    Sprite* sprite = new Sprite("../Assets/evil.png",parent);
    parent.AddComponent(sprite);
    parent.box.h = 32;
    parent.box.w = 32;
}

void LeafMan::Update(){
    std::weak_ptr<GameObject> playerGoPtr = Game::GetInstance().GetCurrentState().GetObjectByComponent("Player");
    std::shared_ptr<GameObject>  playerGo = playerGoPtr.lock();

    //Move enemies towards player
    if (parent.box.x < playerGo->box.x) {
        parent.SetPos(parent.box.x + speed,parent.box.y);
    }
    if (parent.box.x> playerGo->box.x) {
        parent.SetPos(parent.box.x - speed,parent.box.y);
    }
    if (parent.box.y < playerGo->box.y) {
        parent.SetPos(parent.box.x,parent.box.y+speed);
    }
    if (parent.box.y > playerGo->box.y) {
        parent.SetPos(parent.box.x,parent.box.y-speed);
    }
}