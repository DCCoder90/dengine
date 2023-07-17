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
        /**
         * Sets a variable and stores the value in the variables map to be used by UI components later
         * @brief Sets a variable for a component
         * @param key The name of the variable to set
         * @param value The value of the variable to set as a string
         * @see variables
         */
        void SetVar(std::string key,std::string value);
        /**
         * Returns true if the variable is set and false if it isn't.  This function does not check or validate the variable's
         * value, only if it exists or not.
         * @brief Checks if component has a variable set
         * @param key The name of the variable to check
         * @return True if the variable is set
         */
        bool HasVar(std::string key);
    protected:
        std::string GetVar(std::string key);
    private:
        std::map<std::string,std::string> variables;
    };
};

#endif //DENGINE_UICOMPONENT_H
