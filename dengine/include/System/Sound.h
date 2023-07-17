#ifndef DENGINE_SOUND_H
#define DENGINE_SOUND_H

#include <string>
#include <iostream>
#include <SDL.h>
#include "../Universal.h"

namespace dengine {
/**
 * A sound is any audible event within the game, whether it be background music or a quick effect.  Sounds are managed by the
 * AudioManager and are loaded into and called from it.
* @brief A Sound
 * @see AudioManager
*/
    class Sound {

    public:
        /**
    * Create a new sound
         * @brief Constructor
         * @param filepath The filepath to a wav file
    */
        Sound(std::string filepath);

        /**
    * Frees up resources allocated by sound
         * @brief Destructor
    */
        ~Sound();

        /**
    * @brief Loads sound into memory
    */
        void LoadSound();

        /**
    * @brief Plays the sound
    */
        void PlaySound();

        /**
    * @brief Stops the sound from playing
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
        Uint8 *m_waveStart;
        /**
    * The length of the wave data
    */
        Uint32 m_waveLength;
    };
}

#endif //DENGINE_SOUND_H
