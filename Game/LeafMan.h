//
// Created by ernes on 6/29/2023.
//

#ifndef SDL_LEARN_LEAFMAN_H
#define SDL_LEARN_LEAFMAN_H

#include "../include/System/Component.h"
#include "../include/System/GameObject.h"
#include "../include/Components/Sprite.h"
#include "./Player.h"

class LeafMan : public Component{
public:
    LeafMan(GameObject &parent);
    void Start() override;
    void Update() override;
};


#endif //SDL_LEARN_LEAFMAN_H
