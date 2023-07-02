#ifndef SDL_LEARN_AUDIOMANAGER_H
#define SDL_LEARN_AUDIOMANAGER_H
#include "Sound.h"
#include <map>
#include <memory>

class AudioManager {
public:
    void AddSound(std::string name,std::string filepath);
    void LoadSounds();
    void PlaySound(std::string name);
    void ClearSounds();
    void RemoveSound(std::string name);
    bool HasSound(std::string name);
    static AudioManager& GetInstance();
private:
    static AudioManager* instance;
    std::map<std::string, std::shared_ptr<Sound>> audioCollection;
};


#endif //SDL_LEARN_AUDIOMANAGER_H
