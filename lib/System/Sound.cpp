#include "../../include/System/Sound.h"

Sound::Sound(std::string filepath){
    filePath = filepath;
}

Sound::~Sound(){
    SDL_FreeWAV(m_waveStart);
    SDL_CloseAudioDevice(m_device);
}

void Sound::LoadSound(){
    if(SDL_LoadWAV(filePath.c_str(), &m_audioSpec, &m_waveStart, &m_waveLength) == nullptr){
        LOG_CRIT << SDL_GetError();
    }
    SetupDevice();
}

void Sound::PlaySound(){
    int status = SDL_QueueAudio(m_device, m_waveStart, m_waveLength);
    SDL_PauseAudioDevice(m_device,0);
}

void Sound::StopSound(){
    SDL_PauseAudioDevice(m_device,1);
}

void Sound::SetupDevice(){
    m_device = SDL_OpenAudioDevice(nullptr, 0, &m_audioSpec, nullptr, SDL_AUDIO_ALLOW_ANY_CHANGE);
    if(0 == m_device){
        LOG_CRIT << SDL_GetError();
    }
}
