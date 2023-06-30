//
// Created by ernes on 6/27/2023.
//

#ifndef SDL_LEARN_EVENTSYSTEM_H
#define SDL_LEARN_EVENTSYSTEM_H

#include <SDL.h>
#include <functional>
#include <map>
#include <string>
#include <iostream>

class EventSystem {
public:
    struct CustomEventData;
    struct CustomEvent;

    void processEvents();

    void sendCustomEvent(void *data1, void *data2);

    template<typename EventType>
    void registerHandler(std::function<void(EventType)> handler);

    template<typename EventType>
    void unregisterHandler();

protected:
    virtual void handleCustomEvent(void *data1, void *data2);

    virtual void onQuit();

    virtual void onKeyDown(SDL_Keycode key);

    virtual void onMouseButtonDown(Uint8 button, int x, int y);

private:
    std::map<Uint32, std::function<void(void *, void *)>> eventHandlers;
};

#endif //SDL_LEARN_EVENTSYSTEM_H
