//
// Created by ernes on 6/18/2023.
//

#ifndef SDL_LEARN_ENEMY_H
#define SDL_LEARN_ENEMY_H
#include <SDL.h>
#include <SDL_image.h>

class Enemy {
public:
    Enemy();
    float xPos, yPos;
    SDL_Rect posRect;
    int speed;
    SDL_Texture *texture;
    void SetPos(float xPos, float yPos);
};


#endif //SDL_LEARN_ENEMY_H
