#ifndef DENGINE_FONTMANAGER_H
#define DENGINE_FONTMANAGER_H

#include <map>
#include <string>
#include <SDL_ttf.h>

namespace dengine_UI {
    /**
     * A singleton manager that manages all TTF's in the game
     * @brief Font Manager
     */
    class FontManager {
    public:
        /**
         * Reads a TTF from the filePath and generates a TTF_Font from [SDL_TTF](https://github.com/libsdl-org/SDL_ttf)
         * @brief Add a font to the system
         * @param name The name of the font
         * @param filePath The filepath to the font
         * @param size The font size
         */
        void AddFont(std::string name,std::string filePath, int size);
        /**
         * Destroys a TTF_Font and removes its references, release memory.
         * @brief Remove a font
         * @param name The name of the font
         */
        void RemoveFont(std::string name);
        /**
         * Unloads and destroys all TTF_Fonts
         * @brief Destructor
         */
        ~FontManager();

        SDL_Texture* Text(std::string fontName, SDL_Color color, std::string text);
        /**
         * In order to ensure singleton pattern is maintained, this function is used to retrieve the instance of
         * the FontManager
         * @brief Returns an instance of the font manager
         * @return
         */
        static FontManager &GetInstance();
    private:
        static FontManager *instance;
        std::map<std::string,TTF_Font*> fonts;
    };
}
#endif //DENGINE_FONTMANAGER_H
