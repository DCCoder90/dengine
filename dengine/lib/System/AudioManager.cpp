#include "../../include/System/AudioManager.h"

using namespace dengine;

AudioManager* AudioManager::instance;

void AudioManager::AddSound(std::string name,std::string filepath){
    Sound* sound = new Sound(filepath);
    audioCollection[name]=std::make_shared<Sound>(*sound);
}

void AudioManager::LoadSounds(){
    for (auto it = audioCollection.begin(); it != audioCollection.end(); ++it) {
        it->second->LoadSound();
    }
}

void AudioManager::PlaySound(std::string name){
    LOG_INFO << "Playing Sound";
    audioCollection[name]->PlaySound();
}

void AudioManager::ClearSounds(){
    audioCollection.clear();
}

void AudioManager::RemoveSound(std::string name){
    audioCollection[name]= nullptr;
}

bool AudioManager::HasSound(std::string name){
    return audioCollection.count(name) > 0;
}

AudioManager& AudioManager::GetInstance() {
    if (instance == nullptr) {
        instance = new AudioManager();
    }
    return *instance;
}