#ifndef DENGINE_BASELEVEL_H
#define DENGINE_BASELEVEL_H

#include <SDL.h>
#include <Utils/Serializer.h>
#include <System/GameLevel.h>
#include <System/GameStates.h>
#include <System/Game.h>
#include "../Player.h"
#include <System/Sound.h>
#include <System/AudioManager.h>
#include <UI/Components/ProgressBarH.h>

using namespace dengine;
/**
 * @brief Namespace containing demo game code
 */
namespace DemoGame {
    class BaseLevel : public GameLevel {
    public:
        BaseLevel();

        void Update() override;

        void Render() override;

        void Load() override;

        void UnLoad() override;

        void Start() override;

        void Pause() override;

        void Resume() override;

        void LoadUI();

    private:
        class Player *player;
        int playerHealth = 100;
        ProgressBarH* healthBar;
        std::vector <std::vector<char>> serializedObjects;
    };
}
#endif //DENGINE_BASELEVEL_H
