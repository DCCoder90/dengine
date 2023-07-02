

#ifndef SDL_LEARN_PLAYER_H
#define SDL_LEARN_PLAYER_H

#include "../include/System/Component.h"
#include "../include/System/GameObject.h"
#include "../include/Components/Sprite.h"
#include "../include/Universal.h"


class Player : public Component{
public:
    Player(GameObject &parent);
    void Start() override;
    void Update() override;
private:
    int speed = 3;
};


#endif //SDL_LEARN_PLAYER_H
