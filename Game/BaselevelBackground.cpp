#include "BaselevelBackground.h"

BaselevelBackground::BaselevelBackground(std::string filepath, GameObject &associated) : Component(associated){
    SDL_Surface *tempSurface = IMG_Load(filepath.c_str());

    if (tempSurface == NULL) {
        printf("Failed to load image: %s\n", SDL_GetError());
    }

    texture = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), tempSurface);
    SDL_FreeSurface(tempSurface);

    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_GetWindowSize(Game::GetInstance().window, &windowWidth, &windowHeight);
}

BaselevelBackground::~BaselevelBackground(){
    SDL_DestroyTexture(texture);
}

void BaselevelBackground::Render() {
    int tilesX = (windowWidth / textureWidth)+1;
    int tilesY = (windowHeight / textureHeight)+1;

// Draw the texture at each tile position
    for (int i = 0; i < tilesX; i++) {
        for (int j = 0; j < tilesY; j++) {
            SDL_Rect destRect;
            destRect.x = i * textureWidth;
            destRect.y = j * textureHeight;
            destRect.w = textureWidth;
            destRect.h = textureHeight;

            SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, NULL, &destRect);
        }
    }
}

SDL_Texture *BaselevelBackground::getTexture() {
    return texture;
}