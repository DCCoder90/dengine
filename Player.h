//
// Created by ernes on 6/16/2023.
//

#ifndef SDL_LEARN_PLAYER_H
#define SDL_LEARN_PLAYER_H
#include <SDL.h>


class Player {
public:
    Player();
    float xPos, yPos;
    SDL_Rect posRect;
    int speed;
};


#endif //SDL_LEARN_PLAYER_H
