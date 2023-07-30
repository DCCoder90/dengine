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
         * @tparam Function The type of the callback function
         * @param eventType The event type to register this for
         * @param callback The callback to invoke when the event is triggered
         * @return A unique identifier for the registration
         */
        template <typename Function>
        int registerEventCallback(Uint32 eventType, Function&& callback) {
            customEventCallbacks.push_back(std::make_unique<CustomEventCallback<Function>>(eventType, std::forward<Function>(callback)));
            int identifier = nextCallbackIdentifier++;
            callbackMap[identifier] = customEventCallbacks.end() - 1;
            return identifier;
        }

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

        template <typename Function>
        struct CustomEventCallback : public CustomEventCallbackBase {
            Function callback;
            CustomEventCallback(Uint32 eventType, Function&& cb) : callback(std::forward<Function>(cb)) {
                this->eventType = eventType;
            }
            void execute() override {
                callback();
            }
        };

        std::vector<std::unique_ptr<CustomEventCallbackBase>> customEventCallbacks;
        std::unordered_map<int, std::vector<std::unique_ptr<CustomEventCallbackBase>>::iterator> callbackMap;
        int nextCallbackIdentifier = 0;
    };
}
#endif //DENGINE_EVENTSYSTEM_H
