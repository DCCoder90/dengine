#include "TitleScreen.h"
#include "TitleScreenBackground.h"
#include "../include/UI/FontManager.h"
#include "../include/UI/Components/Text.h"
#include "../Level1/BaseLevel.h"

using namespace DemoGame;

TitleScreen::TitleScreen(){

}

TitleScreen::~TitleScreen(){
    UnLoad();
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
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_T]) {
        if(GameState::GetInstance().getGameState()==GAMESTATES::Pause){
            Resume();
        }else {
            Pause();
        }
    }

    if(keystates[SDL_SCANCODE_SPACE]){
        Game& game = Game::GetInstance();
        DemoGame::BaseLevel* baseLevel = new DemoGame::BaseLevel();
        game.Push(baseLevel);
    }

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

    uiwindow->Push(displayText);

    Game::GetInstance().GetUI()->Push(uiwindow);
}