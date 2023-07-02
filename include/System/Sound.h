#ifndef SDL_LEARN_SOUND_H
#define SDL_LEARN_SOUND_H

#include <string>
#include <iostream>
#include <SDL.h>
#include "../Universal.h"

class Sound{

public:
    Sound(std::string filepath);
    ~Sound();
    void LoadSound();
    void PlaySound();
    void StopSound();

private:
    void SetupDevice();
    std::string filePath;
    SDL_AudioDeviceID m_device;
    SDL_AudioSpec m_audioSpec;
    Uint8*        m_waveStart;
    Uint32        m_waveLength;
};


#endif //SDL_LEARN_SOUND_H
