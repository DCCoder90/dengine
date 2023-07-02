#ifndef SDL_LEARN_SPRITESHEET_H
#define SDL_LEARN_SPRITESHEET_H

#include <SDL.h>
#include <SDL_image.h>
#include "../../include/System/Game.h"
#include "../../include/System/Time.h"
#include "../System/Component.h"



class Animation{
public:
    Animation(): rect({0,0,0,0}), frames(1){}
    Animation(SDL_Rect rect, int frames) : rect(rect), frames(frames){}
    SDL_Rect rect;
    int frames;
};

/**
 * @brief SpriteSheets are used for images that may include multiple depictions or animations
*/
class SpriteSheet : public Component {
public:
    SpriteSheet(std::string filepath, GameObject &parent);
    ~SpriteSheet();
    void SetCurrentAnimation(std::string name);
    void RegisterAnimation(std::string name, int x, int y, int w, int h, int frames);
    void DeregisterAnimation(std::string name);
    bool HasAnimation(std::string name);
    void Render() override;
    void Pause(bool pause);
private:
    std::map<std::string, Animation> animationCollection;
    SDL_Texture *sheet;
    std::string currentAnimation = "";
    bool isPaused = false;
};

#endif //SDL_LEARN_SPRITESHEET_H