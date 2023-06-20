//
// Created by ernes on 6/20/2023.
//

#ifndef SDL_LEARN_CHARACTER_H
#define SDL_LEARN_CHARACTER_H
#include <SDL.h>
#include <SDL_image.h>

class Character {
public:
    float xPos, yPos;
    SDL_Rect posRect;
    int speed;
    SDL_Texture *texture;
    void SetPos(float xPos, float yPos);
};


#endif //SDL_LEARN_CHARACTER_H
