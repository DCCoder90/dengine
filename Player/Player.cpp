//
// Created by ernes on 6/16/2023.
//

#include "Player.h"

Player::Player(){
    xPos = 250.f;
    yPos = 100.f;
    speed = 3;
    SDL_Texture *texture = NULL;

    posRect = {
            (int)xPos,
            (int)yPos,
            32,
            32
    };
}