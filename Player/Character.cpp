//
// Created by ernes on 6/20/2023.
//

#include "Character.h"


void Character::SetPos(float xPos, float yPos) {
    this->xPos = xPos;
    this->yPos = yPos;
    posRect.x = this->xPos;
    posRect.y = this->yPos;
}