#ifndef SDL_LEARN_BASELEVEL_H
#define SDL_LEARN_BASELEVEL_H

#include <SDL.h>
#include "../include/System/GameLevel.h"
#include "../include/System/GameStates.h"
#include "../include/System/Game.h"
#include "Player.h"
#include "../include/System/Sound.h"
#include "../include/System/AudioManager.h"

using namespace dengine;

class BaseLevel : public GameLevel{
public:
    BaseLevel();
    void Update() override;
    void Render() override;
    void Load() override;
    void Start() override;
    void Pause() override;
    void Resume() override;
private:
    class Player *player;
};

#endif //SDL_LEARN_BASELEVEL_H
