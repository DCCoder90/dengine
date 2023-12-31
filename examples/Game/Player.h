#ifndef DENGINE_PLAYER_H
#define DENGINE_PLAYER_H

#include <System/Component.h>
#include <System/GameObject.h>
#include <Components/Sprite.h>
#include <Universal.h>
#include <Components/SpriteSheet.h>
#include <System/AudioManager.h>

using namespace dengine;

namespace DemoGame {
    class Player : public GameObject {
    public:
        Player();

        void Start() override;

        void Update() override;

        int GetHealth();
        void Damage(int amount);

    private:
        int health =100;
        SpriteSheet *spriteSheet;
        int speed = 3;
        bool spaceKeyDown = false;
    };
}

#endif //DENGINE_PLAYER_H
