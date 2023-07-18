#include "../../../include/UI/Components/Text.h"

using namespace dengine_UI;
using namespace dengine;

void Text::Setup(std::string font, std::string text, SDL_Rect rect) {
    textRect = rect;
    fontName = font;
    displayText = text;
}

void Text::Render() {
    SDL_Texture* fontText = FontManager::GetInstance().Text(fontName,{drawColor.r, drawColor.g, drawColor.b},displayText);
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), fontText, NULL, &textRect);
}