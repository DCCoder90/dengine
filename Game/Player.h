//
// Created by ernes on 6/29/2023.
//

#ifndef SDL_LEARN_PLAYER_H
#define SDL_LEARN_PLAYER_H

#include "../include/System/Component.h"
#include "../include/System/GameObject.h"
#include "../include/Components/Sprite.h"

class Player : public Component{
public:
    Player(GameObject &parent);
    void Start() override;
    static Player& GetInstance();
    static GameObject& GetParent();

private:
    static Player instance;
};


#endif //SDL_LEARN_PLAYER_H
