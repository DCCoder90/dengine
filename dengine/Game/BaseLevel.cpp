#include "BaseLevel.h"
#include "LeafMan.h"
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
    AudioManager::GetInstance().AddSound("death","./Assets/deaths.wav");
    AudioManager::GetInstance().AddSound("fire","./Assets/foom_0.wav");
    AudioManager::GetInstance().LoadSounds();
    AudioManager::GetInstance().PlaySound("background");

    GameObject* managerGo = new GameObject("LevelManager");
    BaselevelBackground* background = new BaselevelBackground("./Assets/grass.png",*managerGo);
    managerGo->AddComponent(background);
    objects.emplace_back(managerGo);

    player = new Player();
    objects.emplace_back(player);


    for (int i = 0; i < 2; i++) {
        LeafMan* enemy = new LeafMan();
        enemy->SetPos(i*150,i*80);
        objects.emplace_back(enemy);
    }

    LoadUI();
}

void BaseLevel::UnLoad() {
    AudioManager::GetInstance().RemoveSound("background");
    AudioManager::GetInstance().RemoveSound("death");
    AudioManager::GetInstance().RemoveSound("fire");
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


    for(int i=0;i<objects.size();i++){
        if(objects[i]->GetName() == "LeafMan"){
            if (objects[i]->box.x + objects[i]->box.w>= player->box.x &&
                    objects[i]->box.x <= player->box.x + player->box.w &&
                    objects[i]->box.y + objects[i]->box.h >= player->box.y &&
                    objects[i]->box.y <= player->box.y + player->box.h) {

                if(player->GetHealth() <= 0){
                    GameState::GetInstance().setGameState(GAMESTATES::Gameover);
                }

                player->Damage(10);

                healthBar->SetCompleted(player->GetHealth());

                AudioManager::GetInstance().PlaySound("death");
                objects[i]->box.x = 0;
                objects[i]->box.y = 0;
            }
        }
    }

        UpdateObjects();
}

void BaseLevel::Render() {
    RenderObjects();
}

void BaseLevel::LoadUI() {
    FontManager::GetInstance().AddFont("SpaceSmall","Space_Pontiff.ttf",80);

    UIWindow* uiwindow = new UIWindow();
    healthBar = new ProgressBarH();
    healthBar->Setup({0,0},100);
    healthBar->SetDrawColor({255,255,255,255});
    healthBar->SetFillColor({255,0,0,255});


    Text* displayText = new Text();
    SDL_Rect displayRect = {200,0,300,80};
    displayText->Setup("SpaceSmall","Example Game",displayRect);
    displayText->SetDrawColor({255,255,255,255});


    RoundedBox* roundedBox = new RoundedBox();
    roundedBox->Setup({0,200,150,30},0.5,2);
    roundedBox->SetDrawColor({255,165,0,255});

    HollowRect* hollowRect = new HollowRect();
    hollowRect->Setup({50,250,150,30},10);
    hollowRect->SetDrawColor({255,165,98,255});

    Circle* circle = new Circle();
    circle->Setup({200,250},80);
    circle->SetDrawColor({153,0,76,255});


    FilledCircle* filledcircle = new FilledCircle();
    filledcircle->Setup({290,250},80);
    filledcircle->SetDrawColor({255,51,153,255});


    uiwindow->Push(healthBar);
    uiwindow->Push(displayText);
    uiwindow->Push(roundedBox);
    uiwindow->Push(hollowRect);
    uiwindow->Push(circle);
    uiwindow->Push(filledcircle);

    Game::GetInstance().GetUI()->Push(uiwindow);
}