#include "BaseLevel.h"
#include "../LeafMan.h"
#include "BaselevelBackground.h"

//#include "../include/UI/Components/ProgressBarV.h"
#include "../include/UI/Components/ProgressBarH.h"
#include "../include/UI/FontManager.h"
#include "../include/UI/Components/Text.h"
#include "../include/UI/Components/RoundedBox.h"
#include "../include/UI/Components/HollowRect.h"
#include "../include/UI/Components/Circle.h"
#include "../include/UI/Components/FilledCircle.h"
#include "../include/Vec2.h"

using namespace DemoGame;

BaseLevel::BaseLevel(){

}

void BaseLevel::Load(){
    AudioManager::GetInstance().AddSound("background","./Assets/background.wav");
    AudioManager::GetInstance().LoadSounds();
    AudioManager::GetInstance().PlaySound("background");

    GameObject* managerGo = new GameObject("LevelManager");
    BaselevelBackground* background = new BaselevelBackground("./Assets/dark-background.png",*managerGo);
    managerGo->AddComponent(background);
    objects.emplace_back(managerGo);

    LoadUI();
}

void BaseLevel::UnLoad() {
    AudioManager::GetInstance().RemoveSound("background");
}

void BaseLevel::Start(){
    StartObjects();
}

void BaseLevel::Pause(){
    GameState::GetInstance().setGameState(GAMESTATES::Pause);
}

void BaseLevel::Resume(){
    GameState::GetInstance().setGameState(GAMESTATES::Playing);
}


void BaseLevel::Update(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_T]) {
        if(GameState::GetInstance().getGameState()==GAMESTATES::Pause){
            Resume();
        }else {
            Pause();
        }
    }


    UpdateObjects();
}

void BaseLevel::Render() {
    RenderObjects();
}

void BaseLevel::LoadUI() {
    FontManager::GetInstance().AddFont("SpaceSmall","./Assets/Fonts/Space_Pontiff.ttf",80);

    UIWindow* uiwindow = new UIWindow();
    healthBar = new ProgressBarH();
    healthBar->Setup({0,0},100);
    healthBar->SetDrawColor({255,255,255,255});
    healthBar->SetFillColor({255,0,0,255});


    Text* displayText = new Text();
    SDL_Rect displayRect = {200,0,300,80};
    displayText->Setup("SpaceSmall","Dark Moon",displayRect);
    displayText->SetDrawColor({255,102,255,255});

    uiwindow->Push(healthBar);
    uiwindow->Push(displayText);

    Game::GetInstance().GetUI()->Push(uiwindow);
}