#ifndef DENGINE_BASELEVEL_H
#define DENGINE_BASELEVEL_H

#include <SDL.h>
#include "../include/Utils/Serializer.h"
#include "../include/System/GameLevel.h"
#include "../include/System/GameStates.h"
#include "../include/System/Game.h"
#include "Player.h"
#include "../include/System/Sound.h"
#include "../include/System/AudioManager.h"


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
        void Serialize() override;
        void Deserialize() override;

        void Start() override;

        void Pause() override;

        void Resume() override;

    private:
        class Player *player;
        std::vector <std::vector<char>> serializedObjects;
    };
}
#endif //DENGINE_BASELEVEL_H
