//
// Created by ernes on 6/16/2023.
//

#include "Player.h"

Player::Player(){
    xPos = 100.f;
    yPos = 100.f;
    speed = 1;

    posRect = {
            (int)xPos,
            (int)yPos,
            32,
            32
    };
}