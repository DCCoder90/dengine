#include "../../include/Components/SpriteSheet.h"
#include "../../include/System/CameraManager.h"

using namespace dengine;

SpriteSheet::SpriteSheet(std::string filepath, GameObject &associated) : Component(associated){
    SDL_Surface* surface = IMG_Load(filepath.c_str());
    //SDL_SetColorKey is then used to set the color key for the surface.
    // The color key is the color that will be replaced with transparency.
    // SDL_MapRGB is used to get the pixel value for white color in the format used by the surface.
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));

    if (surface == nullptr) {
        LOG_CRIT << "Failed to load image: " << IMG_GetError();
    } else {
        sheet = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), surface);
        if (sheet == nullptr) {
            LOG_CRIT << "Failed to create texture: " << SDL_GetError();
        }
        SDL_FreeSurface(surface);
    }
    LOG_INFO << "Loaded Spritesheet";
}

bool SpriteSheet::HasAnimation(std::string name){
    return animationCollection.count(name) > 0;
}

void SpriteSheet::Render(){
    if(!isPaused){
        Uint32 ticks = SDL_GetTicks();
        Uint32 sprite = ((ticks / 100) % animationCollection[currentAnimation].frames);
        SDL_Rect* spriteFrame = new SDL_Rect();

        spriteFrame->x = (sprite*animationCollection[currentAnimation].rect.w)+animationCollection[currentAnimation].rect.x;
        spriteFrame->y = animationCollection[currentAnimation].rect.y;
        spriteFrame->h = animationCollection[currentAnimation].rect.h;
        spriteFrame->w = animationCollection[currentAnimation].rect.w;


        SDL_Rect destRect;
        destRect.x = parent.box.x;
        destRect.y = parent.box.y;
        destRect.w = spriteFrame->w;
        destRect.h = spriteFrame->h;

        SDL_RenderCopy(Game::GetInstance().GetRenderer(),
                       sheet,
                       spriteFrame,
                       &destRect);
    }
}

void SpriteSheet::SetCurrentAnimation(std::string name){
    currentAnimation = name;
}

void SpriteSheet::RegisterAnimation(std::string name, int x, int y, int w, int h, int frames){
    animationCollection[name] = *new Animation({x,y,w,h},frames);
}

void SpriteSheet::DeregisterAnimation(std::string name){
    animationCollection.erase(name);
}

void SpriteSheet::Pause(bool pause){
    isPaused = pause;
}

SpriteSheet::~SpriteSheet() {
    SDL_DestroyTexture(sheet);
}