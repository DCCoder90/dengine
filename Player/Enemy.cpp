//
// Created by ernes on 6/18/2023.
//

#include "Enemy.h"

Enemy::Enemy(){
    xPos = 200.f;
    yPos = 200.f;
    speed = 1;
    SDL_Texture *texture = NULL;

    posRect = {
            (int)xPos,
            (int)yPos,
            32,
            32
    };
}

void Enemy::SetPos(float xPos, float yPos) {
    this->xPos = xPos;
    this->yPos = yPos;
    posRect.x = this->xPos;
    posRect.y = this->yPos;
}