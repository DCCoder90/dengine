#ifndef DENGINE_EVENTSYSTEM_H
#define DENGINE_EVENTSYSTEM_H

#include <SDL.h>
#include <vector>
#include <functional>
#include <unordered_map>
#include <string>
#include <memory>

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

        /**
         * @brief Register custom event callback function
         * @tparam Args
         * @param eventType The event type to register this for
         * @param callback The callback to invoke when the event is triggered
         * @param args Arguments for the callback
         * @return A unique identifier for the registration
         */
        template <typename... Args>
        int registerEventCallback(Uint32 eventType, std::function<void(Args...)> callback, Args&&... args);

        /**
         * @brief Deregister a custom event callback by its unique identifier
         * @param identifier Unique identifier for an event callback.  Created from registerEventCallback
         */
        void deregisterEventCallback(int identifier);

        /**
         * @brief Process events, including custom events
         */
        void processEvents();

        /**
         * @brief Clean up resources
         */
        void cleanup();

    private:
        struct CustomEventCallbackBase {
            Uint32 eventType;
            virtual void execute() = 0;
            virtual ~CustomEventCallbackBase() {}
        };

        template <typename... Args>
        struct CustomEventCallback : public CustomEventCallbackBase {
            std::function<void(int, Args...)> callback;
            std::tuple<Args...> arguments;

            CustomEventCallback(Uint32 eventType, std::function<void(int, Args...)> cb, Args&&... args)
                    : callback(cb), arguments(std::forward<Args>(args)...) {
                this->eventType = eventType;
            }

            void execute() override {
                std::apply(callback, std::tuple_cat(std::make_tuple(0), arguments)); // Pass '0' as an additional argument to the callback
            }
        };

        std::vector<std::unique_ptr<CustomEventCallbackBase>> customEventCallbacks;
        std::unordered_map<int, std::vector<std::unique_ptr<CustomEventCallbackBase>>::iterator> callbackMap;
        int nextCallbackIdentifier = 0;
    };
}
#endif //DENGINE_EVENTSYSTEM_H
