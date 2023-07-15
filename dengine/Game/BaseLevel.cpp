#include "BaseLevel.h"
#include "LeafMan.h"
#include "BaselevelBackground.h"

#include "../include/UI/Components/ProgressBar.h"
using namespace DemoGame;

BaseLevel::BaseLevel(){
    UIWindow* uiwindow = new UIWindow();
    healthBar = new ProgressBar();
    healthBar->SetVar("xpos","0");
    healthBar->SetVar("completed","100");
    uiwindow->Push(healthBar);

    Game::GetInstance().GetUI()->Push(uiwindow);
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
        GameObject* enemyGo = new GameObject("Enemy " + i);
        LeafMan* enemy = new LeafMan(*enemyGo);
        enemyGo->AddComponent(enemy);
        enemyGo->SetPos(i*150,i*80);
        objects.emplace_back(enemyGo);
    }
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
        if(objects[i]->HasComponent("LeafMan")){
            if (objects[i]->box.x + objects[i]->box.w>= player->box.x &&
                    objects[i]->box.x <= player->box.x + player->box.w &&
                    objects[i]->box.y + objects[i]->box.h >= player->box.y &&
                    objects[i]->box.y <= player->box.y + player->box.h) {

                if(player->GetHealth() <= 0){
                    GameState::GetInstance().setGameState(GAMESTATES::Gameover);
                }

                player->Damage(10);

                healthBar->SetVar("completed",std::to_string(player->GetHealth()));

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