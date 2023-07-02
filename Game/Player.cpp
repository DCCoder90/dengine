

#include "Player.h"

Player::Player(GameObject &parent) : Component(parent) {
    name="Player";
}

void Player::Start() {
    Sprite* sprite = new Sprite("../Assets/circle.png",parent);
    parent.AddComponent(sprite);
    LOG_INFO << "Loaded Player";

    parent.box = {250,100,32,32};
}

void Player::Update(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    std::weak_ptr<GameObject> playerGoPtr = Game::GetInstance().GetCurrentState().GetObjectByComponent("Player");
    std::shared_ptr<GameObject> player = playerGoPtr.lock();
    if (keystates[SDL_SCANCODE_UP]) {
        std::weak_ptr<GameObject> playerGoPtr = Game::GetInstance().GetCurrentState().GetObjectByComponent("Player");
        std::shared_ptr<GameObject> player = playerGoPtr.lock();
        player->SetPos(player->box.x, player->box.y -= speed);
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        player->SetPos(player->box.x, player->box.y += speed);
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        player->SetPos(player->box.x -= speed, player->box.y);
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        player->SetPos(player->box.x += speed, player->box.y);
    }
}