//
// Created by ernes on 6/29/2023.
//

#ifndef SDL_LEARN_SPRITE_H
#define SDL_LEARN_SPRITE_H


#include <SDL.h>
#include "../System/Component.h"
#include "../System/GameObject.h"
#include "../../include/System/Game.h"
#include <SDL_image.h>

class Sprite : public Component {
public:
    Sprite(std::string filepath, GameObject &parent);

    void Render() override;
    SDL_Texture *getTexture();
private:
    SDL_Texture *texture;
};


#endif //SDL_LEARN_SPRITE_H
