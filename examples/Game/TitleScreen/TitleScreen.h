//
// Created by ernes on 7/29/2023.
//

#ifndef GAME_ENGINE_TITLESCREEN_H
#define GAME_ENGINE_TITLESCREEN_H

#include <SDL.h>
#include <System/GameLevel.h>
#include <System/GameStates.h>
#include <System/Game.h>
#include <System/Sound.h>
#include <System/AudioManager.h>

using namespace dengine;

namespace DemoGame {
    class TitleScreen : public GameLevel {
    public:
        TitleScreen();
        ~TitleScreen();

        void Update() override;

        void Render() override;

        void Load() override;

        void UnLoad() override;

        void Start() override;

        void Pause() override;

        void Resume() override;

        void LoadUI();
    };
}

#endif //GAME_ENGINE_TITLESCREEN_H
