#include "../../include/Components/SpriteSheet.h"

SpriteSheet::SpriteSheet(std::string filepath, GameObject &associated) : Component(associated){
    SDL_Surface* surface = IMG_Load(filepath.c_str());
    if (surface == nullptr) {
        LOG_CRIT << "Failed to load image: " << IMG_GetError();
    } else {
        sheet = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), surface);
        if (sheet == nullptr) {
            LOG_CRIT << "Failed to create texture: " << SDL_GetError();
        }
        SDL_FreeSurface(surface);
    }
}

void SpriteSheet::Update(){
    //TODO: Perform animation here
    //Time::GetInstance().frameTicks;
}

void SpriteSheet::Pause(bool pause){
    isPaused = pause;
}

//TODO: Register Animations
//TODO: Set current animation
//TODO: Pause animation
//TODO: Define sprite size h/w
//TODO: Define number of frames in animation