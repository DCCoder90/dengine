

#include "Player.h"
#include "../include/System/AudioManager.h"

Player::Player(GameObject &parent) : Component(parent) {
    name="Player";

}

void Player::Start() {
    spriteSheet = new SpriteSheet("../Assets/warrior-sheet.png",parent);
    spriteSheet->RegisterAnimation("walkdown",2882,1045,96,96,8);
    spriteSheet->RegisterAnimation("walkleft",2882,1142,96,96,8);
    spriteSheet->RegisterAnimation("walkup",2882,1336,96,96,8);
    spriteSheet->RegisterAnimation("walkright",2882,1627,96,96,8);
    spriteSheet->RegisterAnimation("idle",0,1045,96,96,10);
    spriteSheet->RegisterAnimation("fire",0,1827,96,96,20);
    spriteSheet->SetCurrentAnimation("idle");
    spriteSheet->Pause(false);

    parent.AddComponent(spriteSheet);
    LOG_INFO << "Loaded Player";

    parent.box = {250,100,32,32};
}

void Player::Update(){
    int numKeys;
    const Uint8 *keystates = SDL_GetKeyboardState(&numKeys);

    bool noKeysPressed = true;
    for (int i = 0; i < numKeys; i++) {
        if (keystates[i]) {
            noKeysPressed = false;
            break;
        }
    }

    if(noKeysPressed){
        spriteSheet->SetCurrentAnimation("idle");
    }else {
        std::weak_ptr<GameObject> playerGoPtr = Game::GetInstance().GetCurrentState().GetObjectByComponent("Player");
        std::shared_ptr<GameObject> player = playerGoPtr.lock();
        if (keystates[SDL_SCANCODE_UP]) {
            spriteSheet->SetCurrentAnimation("walkup");
            player->SetPos(player->box.x, player->box.y -= speed);
        }
        if (keystates[SDL_SCANCODE_DOWN]) {
            spriteSheet->SetCurrentAnimation("walkdown");
            player->SetPos(player->box.x, player->box.y += speed);
        }
        if (keystates[SDL_SCANCODE_LEFT]) {
            spriteSheet->SetCurrentAnimation("walkleft");
            player->SetPos(player->box.x -= speed, player->box.y);
        }
        if (keystates[SDL_SCANCODE_RIGHT]) {
            spriteSheet->SetCurrentAnimation("walkright");
            player->SetPos(player->box.x += speed, player->box.y);
        }
        if (keystates[SDL_SCANCODE_SPACE]) {
            if(!spaceKeyDown) {
                AudioManager::GetInstance().PlaySound("fire");
                spriteSheet->SetCurrentAnimation("fire");
                spaceKeyDown = true;
            }
        }else{
            spaceKeyDown = false;
        }
    }
}