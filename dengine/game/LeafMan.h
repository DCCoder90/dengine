

#ifndef DENGINE_LEAFMAN_H
#define DENGINE_LEAFMAN_H

#include "../include/System/Component.h"
#include "../include/System/GameObject.h"
#include "../include/Components/Sprite.h"
#include "./Player.h"

using namespace dengine;

namespace DemoGame {
    class LeafMan : public Component {
    public:
        LeafMan(GameObject &parent);

        void Start() override;

        void Update() override;

    private:
        SpriteSheet *spriteSheet;
        int speed = 1;
    };
}

#endif //DENGINE_LEAFMAN_H
