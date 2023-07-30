#include "StartGameButton.h"
void StartGameButton::Update(){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if( event.type == SDL_MOUSEMOTION) {
            CheckMouseHover();
        }else if(event.type == SDL_MOUSEBUTTONUP){
            OnClick();
        }
    }
}

void StartGameButton::CheckMouseHover(){
    int x, y;
    SDL_GetMouseState(&x, &y);

    if(x>textRect.x && x< textRect.x+textRect.h
       && y> textRect.y && y<textRect.y+textRect.w){
        inRect=true;
        LOG_INFO << "Hover";
        SetDrawColor({255,0,0,255});
    }else{
        inRect=false;
        LOG_INFO << "Not Hover";
        SetDrawColor({255,102,255,255});
    }
}

void StartGameButton::OnClick(){
    if(inRect) {
            Game &game = Game::GetInstance();
            DemoGame::BaseLevel *baseLevel = new DemoGame::BaseLevel();
            game.Push(baseLevel);
    }
}