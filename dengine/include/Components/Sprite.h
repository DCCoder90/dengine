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
 * Sprites are used for static images that don't require animation
 * @brief A sprite
*/
    class Sprite : public Component {
    public:
        /**
        * Creates a sprite from the image defined in the filepath
         * @brief Constructor
        */
        Sprite(std::string filepath, GameObject &parent);

        /**
        * Frees up resources allocated by Sprite
         * @brief Desctructor
        */
        ~Sprite();

        /**
    * Renders the sprite
         * @brief Render Function
    */
        void Render() override;

        /**
    * Returns a pointer to the texture
         * @brief Sprite Texture
    */
        SDL_Texture *getTexture();

    private:
        SDL_Texture *texture;
    };
}

#endif //DENGINE_SPRITE_H
