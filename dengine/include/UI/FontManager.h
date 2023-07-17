#ifndef DENGINE_FONTMANAGER_H
#define DENGINE_FONTMANAGER_H

#include <map>
#include <string>
#include <SDL_ttf.h>

namespace dengine {
    /**
     * @brief Manages all TTF's in the game
     */
    class FontManager {
    public:
        /**
         * @brief Add a font to the system
         * @param name The name of the font
         * @param filePath The filepath to the font
         * @param size The font size
         */
        void AddFont(std::string name,std::string filePath, int size);
        /**
         * @brief Remove a font from memory
         * @param name The name of the font
         */
        void RemoveFont(std::string name);
        /**
         * @brief Destructor removes all loaded fonts
         */
        ~FontManager();
        /**
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
