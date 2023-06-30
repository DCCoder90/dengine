//
// Created by ernes on 6/29/2023.
//

#include "LeafMan.h"

LeafMan::LeafMan(GameObject &parent) : Component(parent) {
}

void LeafMan::Start() {
    Sprite* sprite = new Sprite("../Assets/evil.png",parent);
    parent.AddComponent(sprite);
}

void LeafMan::Update(){
    std::weak_ptr<GameObject> playerGoPtr = Game::GetInstance().GetCurrentState().GetObjectByComponent("Player");
    std::shared_ptr<GameObject>  playerGo = playerGoPtr.lock();

    //Move enemies towards player
    if (parent.box.x < playerGo->box.x) {
        parent.SetPos(parent.box.x + 1,parent.box.y);
    }
    if (parent.box.x> playerGo->box.x) {
        parent.SetPos(parent.box.x - 1,parent.box.y);
    }
    if (parent.box.y < playerGo->box.y) {
        parent.SetPos(parent.box.x,parent.box.y+1);
    }
    if (parent.box.y > playerGo->box.y) {
        parent.SetPos(parent.box.x,parent.box.y-1);
    }
}