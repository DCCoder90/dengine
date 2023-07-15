#ifndef DENGINE_FONTMANAGER_H
#define DENGINE_FONTMANAGER_H

#include <map>
#include <string>
#include <SDL_ttf.h>

namespace dengine {
    class FontManager {
    public:
        void AddFont(std::string name,std::string filePath, int size);
        void RemoveFont(std::string name);
        SDL_Texture* Text(std::string fontName, SDL_Color color, std::string text);
        ~FontManager();
        static FontManager &GetInstance();
    private:
        static FontManager *instance;
        std::map<std::string,TTF_Font*> fonts;
    };
}
#endif //DENGINE_FONTMANAGER_H
