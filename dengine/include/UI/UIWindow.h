#ifndef DENGINE_UIWINDOW_H
#define DENGINE_UIWINDOW_H
#include <vector>
#include "UIComponent.h"

namespace dengine_UI{
    /**
     * @brief UI window
     * Meant to be a collection of related UIComponents to display at the same time.  This can be a menu, a HUD, or anything
     * else where you want multiple elements displayed at once.  This will then be "Pushed" to the UI to be displayed.
     * See the code example below for a quick reference on how to use the UIWindow with UIComponent and the UI
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
     * @see UIComponent
     */
    class UIWindow{
    public:
        /**
         * Adds a new UIComponent to the stack.  The stack is a FILO system and as such the last component added will
         * be draw on top.  If you layer UIComponents be mindful of the order they are pushed.
         * @brief Push a component onto the stack
         */
        void Push(UIComponent *);
        /**
         * Removes the last UIComponent added from the stack
         * @brief Pop a UI element from the stack
         */
        void Pop();
        /**
         * Renders all components on the stack
         * @brief Render function
         */
        virtual void Render();

        /**
         * Update all components on the stack
         * @brief Update function
         */
        virtual void Update();

    private:
        std::vector<class UIComponent *> components;
    };
}
#endif //DENGINE_UIWINDOW_H
