#include "TitleScreenBackground.h"

using namespace DemoGame;

TitleScreenBackground::TitleScreenBackground(std::string filepath, GameObject &associated) : Component(associated){
    SDL_Surface *tempSurface = IMG_Load(filepath.c_str());

    if (tempSurface == NULL) {
        printf("Failed to load image: %s\n", SDL_GetError());
    }

    texture = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), tempSurface);
    SDL_FreeSurface(tempSurface);

    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_GetWindowSize(Game::GetInstance().window, &windowWidth, &windowHeight);
}

TitleScreenBackground::~TitleScreenBackground(){
    SDL_DestroyTexture(texture);
}

void TitleScreenBackground::Render() {
    SDL_Rect destRect;
    destRect.x = 0;
    destRect.y = 0;
    destRect.w = windowWidth;
    destRect.h = windowHeight;

    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, NULL, &destRect);
}

SDL_Texture *TitleScreenBackground::getTexture() {
    return texture;
}