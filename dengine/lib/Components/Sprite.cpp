#include "../../include/Components/Sprite.h"

using namespace dengine;

Sprite::Sprite(std::string filepath, GameObject &associated) : Component(associated){
    SDL_Surface *tempSurface = IMG_Load(filepath.c_str());

    if (tempSurface == NULL) {
        printf("Failed to load image: %s\n", SDL_GetError());
    }

    texture = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), tempSurface);
    SDL_FreeSurface(tempSurface);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::Render() {
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture,
                   reinterpret_cast<const SDL_Rect *>(CameraManager::GetInstance().GetMainCamera().get()), &parent.box);
}

SDL_Texture *Sprite::getTexture() {
    return texture;
}