#include "StartGameButton.h"
void StartGameButton::OnClick(){
    if(inRect) {
        Game &game = Game::GetInstance();
        DemoGame::BaseLevel *baseLevel = new DemoGame::BaseLevel();
        game.Push(baseLevel);
    }
}



void StartGameButton::CheckMouseHover(SDL_Event& event){
    if(event.type == SDL_MOUSEMOTION) {
        int x, y;
        SDL_GetMouseState(&x, &y);

        if (x > textRect.x && x < textRect.x + textRect.w
            && y > textRect.y && y < textRect.y + textRect.h) {
            inRect = true;
            SetDrawColor({255, 0, 0, 255});
        } else {
            inRect = false;
            SetDrawColor({255, 102, 255, 255});
        }
    }else if(event.type == SDL_MOUSEBUTTONUP){
        OnClick();
    }
}

void StartGameButton::Start(){
    Game::GetInstance().GetEventSystem()->RegisterEventCallback(SDL_MOUSEMOTION, [this](SDL_Event& event) {
        CheckMouseHover(event);
    });
    Game::GetInstance().GetEventSystem()->RegisterEventCallback(SDL_MOUSEBUTTONUP, [this](SDL_Event& event) {
        CheckMouseHover(event);
    });
}