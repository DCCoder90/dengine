#ifndef DENGINE_EVENTSYSTEM_H
#define DENGINE_EVENTSYSTEM_H

#include <SDL.h>
#include <functional>
#include <map>
#include <string>
#include <iostream>

namespace dengine {
    /**
     * @brief Event System
     * @deprecated Marking this as deprecated as it currently serves no purpose.  As development progresses may find a way
     * to add it in to keep up with system events, until then it will be marked as deprecated so others don't rely on it.
     */
    class EventSystem {
    public:
        /**
         * @brief Customer event data
         */
        struct CustomEventData;
        /**
         * @brief Structure of a custom event
         */
        struct CustomEvent;

        /**
         * Runs handlers for any events that have been registered and/called
         * @brief Process called events
         */
        void processEvents();

        /**
         * Sends an event to any handlers that have been registered
         * @brief Send an event
         * @param data1 Data for the event
         * @param data2 Data for the event
         */
        void sendCustomEvent(void *data1, void *data2);

        template<typename EventType>
        /**
         * Register an event handler to be notified when a system event is processed.
         * @brief Register event handler
         * @tparam EventType The type of event to manage
         * @param handler The handler to be called
         */
        void registerHandler(std::function<void(EventType)> handler);

        template<typename EventType>
        /**
         * Removes an event handler that was previous registered with registerHandler(std::function<void(EventType)> handler)
         * @brief Deregister event handler
         */
        void unregisterHandler();

    protected:
        virtual void handleCustomEvent(void *data1, void *data2);

        virtual void onQuit();

        virtual void onKeyDown(SDL_Keycode key);

        virtual void onMouseButtonDown(Uint8 button, int x, int y);

    private:
        std::map <Uint32, std::function<void(void *, void *)>> eventHandlers;
    };
}
#endif //DENGINE_EVENTSYSTEM_H
