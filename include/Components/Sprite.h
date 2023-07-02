#ifndef SDL_LEARN_SPRITE_H
#define SDL_LEARN_SPRITE_H


#include <SDL.h>
#include "../System/Component.h"
#include "../System/GameObject.h"
#include "../../include/System/Game.h"
#include <SDL_image.h>
#include "../System/CameraManager.h"

/**
 * @brief Sprites are used for static images that don't require animation
*/
class Sprite : public Component {
public:
    Sprite(std::string filepath, GameObject &parent);

    void Render() override;
    SDL_Texture *getTexture();
private:
    SDL_Texture *texture;
};


#endif //SDL_LEARN_SPRITE_H
