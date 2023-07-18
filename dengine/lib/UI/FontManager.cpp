#include <stdexcept>
#include "../../include/UI/FontManager.h"
#include "../../include/System/Game.h"

using namespace dengine_UI;
using namespace dengine;

FontManager* FontManager::instance;

FontManager::~FontManager(){
    for (const auto& pair : fonts) {
        TTF_CloseFont(pair.second);
    }
}

void FontManager::AddFont(std::string name,std::string filePath, int size){
    if(fonts.count(name) <= 0){
        fonts[name] = TTF_OpenFont(("../Assets/Fonts/"+filePath).c_str(), size);
        return;
    }
    //throw std::runtime_error("Font already added");
}

void FontManager::RemoveFont(std::string name) {
    if(fonts.count(name) > 0){
        fonts.erase(name);
    }
}

SDL_Texture* FontManager::Text(std::string fontName, SDL_Color color, std::string text) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(fonts[fontName], text.c_str(), color);
    if (!textSurface) {
        throw std::runtime_error("Failed to create font surface");
    }
    return SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), textSurface);
}

FontManager& FontManager::GetInstance() {
    if (instance == nullptr) {
        instance = new FontManager();
    }
    return *instance;
}