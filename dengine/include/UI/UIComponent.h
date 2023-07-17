//
// Created by ernes on 7/14/2023.
//

#ifndef DENGINE_UICOMPONENT_H
#define DENGINE_UICOMPONENT_H
#include <map>
#include <string>
namespace dengine {
    /**
     * @brief A component of a UI window
     */
    class UIComponent {
    public:
        /**
         * @brief The render method of a component. Displays the component on the screen
         */
        virtual void Render() = 0;
        /**
         * @brief Sets a variable for a component
         * @param key The name of the variable to set
         * @param value The value of the variable to set as a string
         */
        void SetVar(std::string key,std::string value);
        /**
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
