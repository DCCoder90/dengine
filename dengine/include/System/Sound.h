#ifndef SDL_LEARN_SOUND_H
#define SDL_LEARN_SOUND_H

#include <string>
#include <iostream>
#include <SDL.h>
#include "../Universal.h"

/**
* @brief Sound controls audio aspects within the game
 * @see AudioManager
*/
class Sound{

public:
    /**
* Create a new sound
     * @param filepath The filepath to a wav file
*/
    Sound(std::string filepath);
    /**
* Frees up resources allocated by sound
*/
    ~Sound();
    /**
* Loads sound into memory
*/
    void LoadSound();
    /**
* Plays the sound
*/
    void PlaySound();
    /**
* Stops the sound from playing
*/
    void StopSound();

private:
    void SetupDevice();
    /**
* Path to the sound's wave file
*/
    std::string filePath;
    /**
* Id of the audio device to initiate playback on
*/
    SDL_AudioDeviceID m_device;
    /**
* The details of the sound itself to play
*/
    SDL_AudioSpec m_audioSpec;
    /**
* The start of the wave data
*/
    Uint8*        m_waveStart;
    /**
* The length of the wave data
*/
    Uint32        m_waveLength;
};


#endif //SDL_LEARN_SOUND_H
