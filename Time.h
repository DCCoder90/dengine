//
// Created by ernes on 6/16/2023.
//

#ifndef SDL_LEARN_TIME_H
#define SDL_LEARN_TIME_H
#include <SDL.h>
class Time {
public:
    Time();
    Uint32 startTicks;
    Uint32 endTicks;
    float deltaTicks;
    float frameTicks;

    void StartTick();
    void EndTick();
};


#endif //SDL_LEARN_TIME_H
