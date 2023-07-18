#ifndef DENGINE_UICOMPONENT_H
#define DENGINE_UICOMPONENT_H
#include <map>
#include <string>
#include <SDL.h>

namespace dengine_UI {
    /**
     * This is a base level component that by itself does nothing.  This should be used as a building block for other UI
     * components.   UI components are meant to be added to UIWindows and will be rendered from there.
     * @brief A component of a UI window
     * @see UIWindow
     */
    class UIComponent {
    public:
        /**
         * During the render phase of the program, this funtion is what draws the component to the screen.  This should
         * be overridden for any UIComponents and actually be used to draw to the screen using one of the many SDL_Render
         * functions available.
         * @brief The render method of a component.
         */
        virtual void Render() = 0;

        void SetDrawColor(SDL_Color color){
            drawColor = color;
        }
    protected:
        std::string GetVar(std::string key);
        SDL_Color drawColor;
    };
};

#endif //DENGINE_UICOMPONENT_H
