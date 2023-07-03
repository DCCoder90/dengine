#ifndef DENGINE_AUDIOMANAGER_H
#define DENGINE_AUDIOMANAGER_H
#include "Sound.h"
#include <map>
#include <memory>

namespace dengine {
/**
* @brief Manages the loading, unloading, and playing of sounds
 * Designed to be used by individual GameLevels to help manage sounds on a per level basis
 * allowing only sounds for that level to be loaded at the loading screen
 * @see Sound
*/
    class AudioManager {
    public:
        /**
    * Add a sound to the audio manager without loading it into memory
         * @brief Add a sound to audio manager
         * @param filepath Filepath to the wave file
         * @param name The name of the sound
         * @see LoadSounds
    */
        void AddSound(std::string name, std::string filepath);

        /**
    * Loads all added sounds into memory
         * @brief Load added sounds to memory
    */
        void LoadSounds();

        /**
    * Plays a sound through the default audio device
         * @brief Play a sound
     * @param name The name of the sound
    */
        void PlaySound(std::string name);

        /**
    * Clear all currently added and loaded sounds freeing up previously allocated space
         * @brief Clear all stored sounds
    */
        void ClearSounds();

        /**
    * Removes a single sound by name from memory
         * @brief Remove a single sound
         * @param name Name of sound to remove
    */
        void RemoveSound(std::string name);

        /**
    * Checks if sound has been added to audiomanager
         * @brief Check if sound has been added
         * @param name Name of the sound
         * @returns Whether sound currently exists in audiomanager or not
    */
        bool HasSound(std::string name);

/**
* Returns an instance of the audio manager
 */
        static AudioManager &GetInstance();

    private:
        static AudioManager *instance;
        std::map <std::string, std::shared_ptr<Sound>> audioCollection;
    };
}

#endif //DENGINE_AUDIOMANAGER_H
