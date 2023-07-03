#ifndef SDL_LEARN_BASELEVELBACKGROUND_H
#define SDL_LEARN_BASELEVELBACKGROUND_H

#include <SDL.h>
#include <SDL_image.h>
#include "../include/System/Component.h"
#include "../include/System/Game.h"
#include "../include/System/CameraManager.h"

class BaselevelBackground : public Component{
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


#endif //SDL_LEARN_BASELEVELBACKGROUND_H
