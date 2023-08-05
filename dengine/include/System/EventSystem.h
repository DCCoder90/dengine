#ifndef DENGINE_EVENTSYSTEM_H
#define DENGINE_EVENTSYSTEM_H

#include <SDL.h>
#include <vector>
#include <functional>
#include <unordered_map>
#include <string>
#include <memory>
#include <map>
#include "GameStates.h"

namespace dengine {
    /**
    * @brief A struct containing event data
    */
    struct CustomEventData {
        // Define custom data fields here
        int intValue;
        std::string stringValue;
    };

    /**
     * @brief Event System
     */
    class EventSystem {
    public:
        EventSystem();

        typedef std::function<void(SDL_Event&)> EventCallback;
        std::map<Uint32, EventCallback> eventCallbacks;

        /**
         * @brief Function to register an event callback
         * @param eventType The type of event your want this registered for
         * @param callback The callback itself
         *
         * @code
        * void StartGameButton::CheckMouseHover(SDL_Event& event){
        *    if(event.type == SDL_MOUSEMOTION) {
        *         int x, y;
        *         SDL_GetMouseState(&x, &y);
        *
        *         if (x > textRect.x && x < textRect.x + textRect.w
        *             && y > textRect.y && y < textRect.y + textRect.h) {
        *             inRect = true;
        *             SetDrawColor({255, 0, 0, 255});
        *         } else {
        *             inRect = false;
        *             SetDrawColor({255, 102, 255, 255});
        *         }
        *     }else if(event.type == SDL_MOUSEBUTTONUP){
        *         OnClick();
        *     }
        * }
        *
        * void StartGameButton::Start(){
        *     Game::GetInstance().GetEventSystem()->RegisterEventCallback(SDL_MOUSEMOTION, [this](SDL_Event& event) {
        *         CheckMouseHover(event);
        *     });
        *     Game::GetInstance().GetEventSystem()->RegisterEventCallback(SDL_MOUSEBUTTONUP, [this](SDL_Event& event) {
        *         CheckMouseHover(event);
        *     });
        * }
         * @endcode
         */
        void RegisterEventCallback(Uint32 eventType, EventCallback callback) {
            eventCallbacks[eventType] = callback;
        }

        /**
         * @brief Function to deregister an event callback
         * @param eventType The type of event you want to deregister
         */
        void DeregisterEventCallback(Uint32 eventType) {
            eventCallbacks.erase(eventType);
        }

        /**
         * @brief Process events, including custom events
         */
        void processEvents(){
            SDL_Event event;

            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    GameState::GetInstance().setGameState(GAMESTATES::Quit);
                }

                // Check if there's a registered callback for this event type
                if (eventCallbacks.find(event.type) != eventCallbacks.end()) {
                    // Call the registered callback function passing the event as an argument
                    eventCallbacks[event.type](event);
                }
            }
        }

        /**
         * @brief Clean up resources
         */
        void cleanup();
    };
}
#endif //DENGINE_EVENTSYSTEM_H
