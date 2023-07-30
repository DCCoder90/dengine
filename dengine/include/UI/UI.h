#ifndef DENGINE_UI_H
#define DENGINE_UI_H

#include <string>
#include <vector>
#include "UIWindow.h"

namespace dengine_UI {
/**
* @brief Used to manage the UI of a game
 * See the code example below for a quick reference on how to use the UI
 * @code
 *  UIWindow* uiwindow = new UIWindow();
 *  Circle* circle = new Circle();
 *  circle->Setup({200,250},80);
 *
 *  FilledCircle* filledcircle = new FilledCircle();
 *  filledcircle->Setup({290,250},80);
 *  uiwindow->Push(circle);
 *  uiwindow->Push(filledcircle);
 *
 *  Game::GetInstance().GetUI()->Push(uiwindow);
 * @endcode
*/
    class UI {
    public:
        /**
         * Create a new UI
         * @brief Constructor
         */
        UI();

        /**
         * Called in the Load stage of a game.  Used for loading the UI into memory
         * @brief Load the UI
         */
        void Load();

        /**
         * Renders the UI to the screen. Called in the Render stage of the game and is rendered after all GameObjects
         * and their components.
         * @brief Render the UI
         */
        void Render();

        /**
         * Calls the Update function for the UI. Called in the Update stage of the game and is ran before all GameObjects
         * and their components.
         * @brief Render the UI
         */
        void Update();

        /**
         * Push a new UI window onto the stack
         * @brief Push window to stack
         * @param window The window to add to the stack
         */
        void Push(UIWindow* window);
        /**
         * Removes the last added UI window from the stack
         * @brief Pop a UI window from the stack
         */
        void Pop();

    private:
        std::vector<UIWindow*> windows;
    };
}
#endif //DENGINE_UI_H
