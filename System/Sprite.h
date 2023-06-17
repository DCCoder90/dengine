//
// Created by ernes on 6/17/2023.
//

#ifndef SDL_LEARN_SPRITE_H
#define SDL_LEARN_SPRITE_H

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

class Sprite {
public:
    Sprite(std::string filepath, SDL_Renderer* renderer);
    SDL_Texture* getTexture();

private:
    SDL_Texture* texture;
};


#endif //SDL_LEARN_SPRITE_H
