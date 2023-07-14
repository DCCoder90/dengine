#ifndef DENGINE_UI_H
#define DENGINE_UI_H

#include <string>
#include <map>

namespace dengine {
/**
* @brief Time is used to help manage gametime, refresh rates, ticks and more
*/
    class UI {
    public:
        UI();

        /**
         * @brief Load the UI
         */
        void Load();

        /**
         * @brief Render the UI
         */
        void Render();

        void Update();

        /**
         * @brief Set a variable within the UI
         * @param name Name of the variable
         * @param value Value of the variable
         */
        void SetVar(std::string name, std::string value);

    private:
        std::map<std::string, std::string> variables;
    };
}
#endif //DENGINE_UI_H
