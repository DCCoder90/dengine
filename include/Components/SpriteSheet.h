#ifndef SDL_LEARN_SPRITESHEET_H
#define SDL_LEARN_SPRITESHEET_H

#include <SDL.h>
#include <SDL_image.h>
#include "../../include/System/Game.h"
#include "../../include/System/Time.h"
#include "../System/Component.h"

class SpriteSheet : public Component {
public:
    SpriteSheet(std::string filepath, GameObject &parent);
    void RegisterAnimation();
    void DeregisterAnimation();
    void Update() override;
    void Pause(bool pause);
private:
    SDL_Texture *sheet;
    bool isPaused = false;
};


#endif //SDL_LEARN_SPRITESHEET_H
