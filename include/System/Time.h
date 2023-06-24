//
// Created by ernes on 6/16/2023.
//

#ifndef SDL_LEARN_TIME_H
#define SDL_LEARN_TIME_H
#include <SDL.h>
class Time {
public:
    Time();
    float deltaTicks;
    float frameTicks;

    void StartTick();
    void EndTick();

private:
    Uint32 startTicks = 0;
    Uint32 endTicks = 0;
};


#endif //SDL_LEARN_TIME_H
