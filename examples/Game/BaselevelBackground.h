#ifndef DENGINE_BASELEVELBACKGROUND_H
#define DENGINE_BASELEVELBACKGROUND_H

#include <SDL.h>
#include <SDL_image.h>
#include <System/Component.h>
#include <System/Game.h>
#include <System/CameraManager.h>

using namespace dengine;

namespace DemoGame {

    class BaselevelBackground : public Component {
    public:
        /**
    * Creates a sprite object
    */
        BaselevelBackground(std::string filepath, GameObject &parent);

        /**
    * Frees up resources allocated by Sprite
    */
        ~BaselevelBackground();

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
        int textureWidth, textureHeight;
        int windowWidth, windowHeight;
    };
}

#endif //DENGINE_BASELEVELBACKGROUND_H