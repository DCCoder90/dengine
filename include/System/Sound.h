#ifndef SDL_LEARN_SOUND_H
#define SDL_LEARN_SOUND_H

#include <string>
#include <iostream>
#include <SDL.h>

class Sound{

public:
    Sound(std::string filepath);
    ~Sound();
    void PlaySound();
    void StopSound();
    void SetupDevice();

private:
    SDL_AudioDeviceID m_device;
    SDL_AudioSpec m_audioSpec;
    Uint8*        m_waveStart;
    Uint32        m_waveLength;
};


#endif //SDL_LEARN_SOUND_H