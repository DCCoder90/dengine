#ifndef DENGINE_TIME_H
#define DENGINE_TIME_H

#include <SDL.h>

namespace dengine {
/**
* @brief Time is used to help manage gametime, refresh rates, ticks and more
*/
    class Time {
    public:
        Time();

        float deltaTicks;
        /**
    * @brief The number of ticks per frame
    */
        float frameTicks;

        /**
     * To be run at the beginning of a frame, logs the start tick of the frame
         * @brief Perform a tick at the beginning of the frame
     */
        void StartTick();

        /**
     * To be run at the end of the frame, logs the end tick of the frame and calculates the framerate
         * @brief Perform a tick at the end of the frame
     */
        void EndTick();

        /**
    * @brief Returns an instance to Time
    */
        static Time &GetInstance();

    private:
        Uint32 startTicks = 0;
        Uint32 endTicks = 0;
        static Time instance;
    };
}

#endif //DENGINE_TIME_H
