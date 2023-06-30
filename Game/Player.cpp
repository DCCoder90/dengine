//
// Created by ernes on 6/29/2023.
//

#include "Player.h"

Player::Player(GameObject &parent) : Component(parent) {
    name="Player";
}

void Player::Start() {
    Sprite* sprite = new Sprite("../Assets/circle.png",parent);
    parent.AddComponent(sprite);
    SDL_Log("Loaded Player");

    parent.box = {250,100,32,32};
}