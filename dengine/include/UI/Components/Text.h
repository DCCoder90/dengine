#ifndef DENGINE_TEXT_H
#define DENGINE_TEXT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "../UIComponent.h"
#include "../../System/Game.h"
#include "../FontManager.h"

namespace dengine {
    class Text : public UIComponent {
    public:
        void Setup(std::string font, std::string text, SDL_Rect rect);

        void Render() override;

    private:
        SDL_Rect textRect;
        std::string fontName;
        std::string displayText;
    };
}
#endif //DENGINE_TEXT_H
