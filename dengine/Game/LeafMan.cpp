#include "LeafMan.h"

using namespace DemoGame;

LeafMan::LeafMan(GameObject &parent) : Component(parent) {
    name = "LeafMan";
}

void LeafMan::Start() {
    spriteSheet = new SpriteSheet("../Assets/demon-sheet.png",parent);
    spriteSheet->RegisterAnimation("walkdown",2306,1045,127,127,8);
    spriteSheet->RegisterAnimation("walkleft",2306,1303,127,127,8);
    spriteSheet->RegisterAnimation("walkup",2306,1561,127,127,8);
    spriteSheet->RegisterAnimation("walkright",2306,1819,127,127,8);
    spriteSheet->RegisterAnimation("idle",1025,1045,127,127,10);
    spriteSheet->SetCurrentAnimation("idle");
    spriteSheet->Pause(false);

    parent.AddComponent(spriteSheet);
    parent.box.h = 32;
    parent.box.w = 32;
}

void LeafMan::Update(){

    if(GameState::GetInstance().getGameState()==GAMESTATES::Pause){
        return;
    }

    std::weak_ptr<GameObject> playerGoPtr = Game::GetInstance().GetCurrentState().GetObject("Player");
    std::shared_ptr<GameObject>  playerGo = playerGoPtr.lock();

    //Move enemies towards player
    if (parent.box.x < playerGo->box.x) {
        spriteSheet->SetCurrentAnimation("walkdown");
        parent.SetPos(parent.box.x + speed,parent.box.y);
    }
    if (parent.box.x> playerGo->box.x) {
        spriteSheet->SetCurrentAnimation("walkup");
        parent.SetPos(parent.box.x - speed,parent.box.y);
    }
    if (parent.box.y < playerGo->box.y) {
        spriteSheet->SetCurrentAnimation("walkright");
        parent.SetPos(parent.box.x,parent.box.y+speed);
    }
    if (parent.box.y > playerGo->box.y) {
        spriteSheet->SetCurrentAnimation("walkleft");
        parent.SetPos(parent.box.x,parent.box.y-speed);
    }
}