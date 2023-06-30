//
// Created by ernes on 6/29/2023.
//

#include "Player.h"


Player::Player(GameObject &parent) : Component(parent) {
}

void Player::Start() {
    Sprite* sprite = new Sprite("../Assets/circle.png",parent);
    parent.AddComponent(sprite);
}

Player& Player::GetInstance() {
    return instance;
}

GameObject& Player::GetParent() {
    return GetInstance().parent;
}