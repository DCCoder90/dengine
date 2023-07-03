#ifndef DENGINE_SPRITE_H
#define DENGINE_SPRITE_H


#include <SDL.h>
#include "../System/Component.h"
#include "../System/GameObject.h"
#include "../System/Game.h"
#include <SDL_image.h>
#include "../System/CameraManager.h"

namespace dengine {
/**
 * @brief Sprites are used for static images that don't require animation
*/
    class Sprite : public Component {
    public:
        /**
    * Creates a sprite object
    */
        Sprite(std::string filepath, GameObject &parent);

        /**
    * Frees up resources allocated by Sprite
    */
        ~Sprite();

        /**
    * Renders the sprite
    */
        void Render() override;

        /**
    * Returns a pointer to the texture
    */
        SDL_Texture *getTexture();

    private:
        SDL_Texture *texture;
    };
}

#endif //DENGINE_SPRITE_H
