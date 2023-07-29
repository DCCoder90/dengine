#include "LeafMan.h"

using namespace DemoGame;

LeafMan::LeafMan() : GameObject("LeafMan") {
    AddTag("Enemy");
}

void LeafMan::Start() {
    spriteSheet = new SpriteSheet("./Assets/demon-sheet.png",*this);
    spriteSheet->RegisterAnimation("walkdown",2306,1045,127,127,8);
    spriteSheet->RegisterAnimation("walkleft",2306,1303,127,127,8);
    spriteSheet->RegisterAnimation("walkup",2306,1561,127,127,8);
    spriteSheet->RegisterAnimation("walkright",2306,1819,127,127,8);
    spriteSheet->RegisterAnimation("idle",1025,1045,127,127,10);
    spriteSheet->SetCurrentAnimation("idle");
    spriteSheet->Pause(false);

    AddComponent(spriteSheet);
    box.h = 32;
    box.w = 32;
}

void LeafMan::Update(){

    if(GameState::GetInstance().getGameState()==GAMESTATES::Pause){
        return;
    }

    std::weak_ptr<GameObject> playerGoPtr = Game::GetInstance().GetCurrentState().GetObject("Player");
    std::shared_ptr<GameObject>  playerGo = playerGoPtr.lock();

    //Move enemies towards player
    if (box.x < playerGo->box.x) {
        spriteSheet->SetCurrentAnimation("walkdown");
        SetPos(box.x + speed,box.y);
    }
    if (box.x> playerGo->box.x) {
        spriteSheet->SetCurrentAnimation("walkup");
        SetPos(box.x - speed,box.y);
    }
    if (box.y < playerGo->box.y) {
        spriteSheet->SetCurrentAnimation("walkright");
        SetPos(box.x,box.y+speed);
    }
    if (box.y > playerGo->box.y) {
        spriteSheet->SetCurrentAnimation("walkleft");
        SetPos(box.x,box.y-speed);
    }
}