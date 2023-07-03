#include "../../include/System/EventSystem.h"

using namespace dengine;

const Uint32 CustomEventType = SDL_USEREVENT + 1;

struct EventSystem::CustomEventData {
    std::string message;
};

struct EventSystem::CustomEvent {
    static Uint32 getType() {
        return CustomEventType;
    }

    CustomEventData data;
};

void EventSystem::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                onQuit();
                break;
            case SDL_KEYDOWN:
                onKeyDown(event.key.keysym.sym);
                break;
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event.button.button, event.button.x, event.button.y);
                break;
            case CustomEventType:
                handleCustomEvent(event.user.data1, event.user.data2);
                break;
        }
    }
}

void EventSystem::sendCustomEvent(void *data1, void *data2) {
    SDL_Event event;
    event.type = CustomEventType;
    event.user.data1 = data1;
    event.user.data2 = data2;
    SDL_PushEvent(&event);
}

template<typename EventType>
void EventSystem::registerHandler(std::function<void(EventType)> handler) {
    eventHandlers[EventType::getType()] = [handler](void *data1, void *data2) {
        handler(*static_cast<EventType *>(data1));
    };
}

template<typename EventType>
void EventSystem::unregisterHandler() {
    eventHandlers.erase(EventType::getType());
}

void EventSystem::onQuit() {
    std::cout << "Quit event received" << std::endl;
}

void EventSystem::onKeyDown(SDL_Keycode key) {
    std::cout << "Key down event received: " << SDL_GetKeyName(key) << std::endl;
}

void EventSystem::onMouseButtonDown(Uint8 button, int x, int y) {
    std::cout << "Mouse button down event received: Button=" << static_cast<int>(button)
              << " X=" << x << " Y=" << y << std::endl;
}

void EventSystem::handleCustomEvent(void *data1, void *data2) {
    CustomEventData *eventData = static_cast<CustomEventData *>(data1);
    std::cout << "Custom event received: " << eventData->message << std::endl;
}



/*
 *     eventSystem.registerHandler<EventSystem::CustomEvent>([](EventSystem::CustomEvent event) {
        std::cout << "Custom event received (Lambda): " << event.data.message << std::endl;
    });

    // Send custom event
    EventSystem::CustomEventData eventData;
    eventData.message = "Hello, Custom Event!";
    eventSystem.sendCustomEvent(&eventData, nullptr);
 *
 */