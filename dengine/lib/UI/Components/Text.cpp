#include "../../../include/UI/Components/Text.h"

void Text::Setup(std::string font, std::string text, SDL_Rect rect) {
    textRect = rect;
    fontName = font;
    displayText = text;
}

void Text::Render() {
    SDL_Texture* fontText = FontManager::GetInstance().Text(fontName,{255, 255, 255},displayText);
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), fontText, NULL, &textRect);
}