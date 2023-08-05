#ifndef GAME_ENGINE_STARTGAMEBUTTON_H
#define GAME_ENGINE_STARTGAMEBUTTON_H
#include <SDL.h>

#include <UI/Components/Text.h>
#include "../Level1/BaseLevel.h"

using namespace dengine_UI;

class StartGameButton : public Text{
public:
    void Start();
    void OnClick();
    void CheckMouseHover(SDL_Event& event);
private:
    bool inRect = false;
};


#endif //GAME_ENGINE_STARTGAMEBUTTON_H
