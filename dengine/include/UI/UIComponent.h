#ifndef DENGINE_UICOMPONENT_H
#define DENGINE_UICOMPONENT_H
#include <map>
#include <string>
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
    protected:
        std::string GetVar(std::string key);
    private:
        std::map<std::string,std::string> variables;
    };
};

#endif //DENGINE_UICOMPONENT_H
