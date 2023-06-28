//
// Created by ernes on 6/17/2023.
//

#include "../../include/System/Sprite.h"

Sprite::Sprite(std::string filepath, SDL_Renderer *renderer) {
    SDL_Surface *tempSurface = IMG_Load(filepath.c_str());

    if (tempSurface == NULL) {
        printf("Failed to load image: %s\n", SDL_GetError());
    }

    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

SDL_Texture *Sprite::getTexture() {
    return texture;
}