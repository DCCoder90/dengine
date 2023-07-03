

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
private:
    SpriteSheet* spriteSheet;
    int speed = 1;
};


#endif //SDL_LEARN_LEAFMAN_H