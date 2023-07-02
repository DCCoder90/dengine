

#ifndef SDL_LEARN_PLAYER_H
#define SDL_LEARN_PLAYER_H

#include "../include/System/Component.h"
#include "../include/System/GameObject.h"
#include "../include/Components/Sprite.h"
#include "../include/Universal.h"
#include "../include/Components/SpriteSheet.h"


class Player : public Component{
public:
    Player(GameObject &parent);
    void Start() override;
    void Update() override;
private:
    SpriteSheet* spriteSheet;
    int speed = 3;
};


#endif //SDL_LEARN_PLAYER_H
