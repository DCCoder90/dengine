#include "BaseLevel.h"
#include "LeafMan.h"
#include "BaselevelBackground.h"

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

    GameObject* playerGo = new GameObject("Player");
    Player* player = new Player(*playerGo);
    playerGo->AddComponent(player);
    objects.emplace_back(playerGo);


    for (int i = 0; i < 2; i++) {
        GameObject* enemyGo = new GameObject("Enemy " + i);
        LeafMan* enemy = new LeafMan(*enemyGo);
        enemyGo->AddComponent(enemy);
        enemyGo->SetPos(i*150,i*80);
        objects.emplace_back(enemyGo);
    }
}

void BaseLevel::Start(){
    StartObjects();
}

void BaseLevel::Pause(){}
void BaseLevel::Resume(){}


void BaseLevel::Update(){

    std::weak_ptr<GameObject> player = Game::GetInstance().GetCurrentState().GetObjectByComponent("Player");
    std::shared_ptr<GameObject> playerGo = player.lock();
    for(int i=0;i<objects.size();i++){
        if(objects[i]->HasComponent("LeafMan")){
            if (objects[i]->box.x + objects[i]->box.w>= playerGo->box.x &&
                    objects[i]->box.x <= playerGo->box.x + playerGo->box.w &&
                    objects[i]->box.y + objects[i]->box.h >= playerGo->box.y &&
                    objects[i]->box.y <= playerGo->box.y + playerGo->box.h) {

                AudioManager::GetInstance().PlaySound("death");
                GameState::GetInstance().setGameState(GAMESTATES::Gameover);
                SDL_Delay(1000);
            }
        }
    }

        UpdateObjects();
}

void BaseLevel::Render() {
    RenderObjects();
}

/*
void BaseLevel::updatestuff() {
        //Check enemy collision

        //Just a simple collision that will be able to tell if right or bottom side of
        //enemy touches player or if enemy is fully on top of player.   Need to fix
        //this though so we only check if we know for sure player and enemy are near each other.
        if (enemies[i]->xPos + enemies[i]->posRect.w >= player->xPos &&
            enemies[i]->xPos <= player->xPos + player->posRect.w &&
            enemies[i]->yPos + enemies[i]->posRect.h >= player->yPos &&
            enemies[i]->yPos <= player->yPos + player->posRect.h) {
            GameState::GetInstance().setGameState(GAMESTATES::Gameover);
        }
    }


}
 */