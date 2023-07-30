#include "../../include/System/EventSystem.h"

using namespace dengine;

EventSystem::EventSystem() {}

template <typename... Args>
int EventSystem::registerEventCallback(Uint32 eventType, std::function<void(Args...)> callback, Args&&... args) {
    customEventCallbacks.push_back(new CustomEventCallback<Args...>(eventType, callback, std::forward<Args>(args)...));
    int identifier = nextCallbackIdentifier++;
    callbackMap[identifier] = customEventCallbacks.end() - 1;
    return identifier;
}

void EventSystem::deregisterEventCallback(int identifier) {
    auto iter = callbackMap.find(identifier);
    if (iter != callbackMap.end()) {
        customEventCallbacks.erase(iter->second);
        callbackMap.erase(iter);
    }
}

void EventSystem::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        for (const auto& customEvent : customEventCallbacks) {
            if (event.type == customEvent->eventType) {
                customEvent->execute();
            }
        }
    }
}

void EventSystem::cleanup() {
    customEventCallbacks.clear();
    callbackMap.clear();
}

/**
 * @brief Destructor for CustomEventData to be used with SDL_PushEvent
 * @param data Data to delete
 */
static void deleteCustomEventData(void* data) {
    CustomEventData* eventData = static_cast<CustomEventData*>(data);
    delete eventData;
}