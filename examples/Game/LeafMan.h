

#ifndef DENGINE_LEAFMAN_H
#define DENGINE_LEAFMAN_H

#include <System/Component.h>
#include <System/GameObject.h>
#include <Components/Sprite.h>
#include "./Player.h"

using namespace dengine;

namespace DemoGame {
    class LeafMan : public GameObject {
    public:
        LeafMan();

        void Start() override;

        void Update() override;

    private:
        SpriteSheet *spriteSheet;
        int speed = 1;
    };
}

#endif //DENGINE_LEAFMAN_H
