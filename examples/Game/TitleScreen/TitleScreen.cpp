#include "TitleScreen.h"
#include "TitleScreenBackground.h"
#include "../include/UI/FontManager.h"
#include "../include/UI/Components/Text.h"
#include "../Level1/BaseLevel.h"
#include "StartGameButton.h"
#include <SDL.h>

using namespace DemoGame;

TitleScreen::TitleScreen(){

}

TitleScreen::~TitleScreen(){
    UnLoad();
}

void OnPause(SDL_Event& event){
    if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_t){

        if(GameState::GetInstance().getGameState()==GAMESTATES::Pause){
            GameState::GetInstance().setGameState(GAMESTATES::Playing);
            LOG_INFO << "Playing";
        }else {
            GameState::GetInstance().setGameState(GAMESTATES::Pause);
            LOG_INFO << "Pause";
        }
    }
}

void TitleScreen::Load(){
    AudioManager::GetInstance().AddSound("background","./Assets/background.wav");
    AudioManager::GetInstance().LoadSounds();
    AudioManager::GetInstance().PlaySound("background");

    GameObject* managerGo = new GameObject("LevelManager");
    TitleScreenBackground* background = new TitleScreenBackground("./Assets/dark-background.png",*managerGo);
    managerGo->AddComponent(background);
    objects.emplace_back(managerGo);

    LoadUI();

    Game::GetInstance().GetEventSystem()->RegisterEventCallback(SDL_KEYDOWN,OnPause);
}

void TitleScreen::UnLoad() {
    AudioManager::GetInstance().RemoveSound("background");
}

void TitleScreen::Start(){
    StartObjects();
}

void TitleScreen::Pause(){
    GameState::GetInstance().setGameState(GAMESTATES::Pause);
}

void TitleScreen::Resume(){
    GameState::GetInstance().setGameState(GAMESTATES::Playing);
}

void TitleScreen::Update(){
    UpdateObjects();
}

void TitleScreen::Render() {
    RenderObjects();
}

void TitleScreen::LoadUI() {
    FontManager::GetInstance().AddFont("SpaceSmall","./Assets/Fonts/Space_Pontiff.ttf",80);

    UIWindow* uiwindow = new UIWindow();

    Text* displayText = new Text();
    SDL_Rect displayRect = {200,0,300,80};
    displayText->Setup("SpaceSmall","Dark Moon",displayRect);
    displayText->SetDrawColor({255,102,255,255});

    SDL_Rect displayRectT = {0,100,300,80};
    StartGameButton* startGameButton = new StartGameButton();
    startGameButton->Setup("SpaceSmall","Start Game",displayRectT);
    startGameButton->SetDrawColor({255,102,255,255});
    startGameButton->Start();

    uiwindow->Push(displayText);
    uiwindow->Push(startGameButton);

    Game::GetInstance().GetUI()->Push(uiwindow);
}