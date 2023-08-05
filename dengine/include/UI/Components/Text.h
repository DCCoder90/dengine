#ifndef DENGINE_TEXT_H
#define DENGINE_TEXT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "../UIComponent.h"
#include "../../System/Game.h"
#include "../FontManager.h"

namespace dengine_UI {
    /**
     * @brief Text rendered with TrueTypeFonts
     */
    class Text : public UIComponent {
    public:
        /**
         * Initializes Text to be displayed on screen
         * @param font The name of the font registered with the FontManager
         * @param text The text to display
         * @param rect A rect denoting the position of the text
         * @see FontManager
         */
        void Setup(std::string font, std::string text, SDL_Rect rect);

        void SetDrawColor(SDL_Color color){
            drawColor = color;
        }

        void Render() override;
        void Update() override;

    protected:
        SDL_Rect textRect;
        std::string fontName;
        std::string displayText;
        SDL_Color drawColor;

    };
}
#endif //DENGINE_TEXT_H
