#include "BaseLevel.h"
#include "LeafMan.h"
#include "BaselevelBackground.h"
#include "../include/Utils/Serializer.h"

using namespace DemoGame;

BaseLevel::BaseLevel(){
}

void BaseLevel::Serialize() {
    Pause();

    for (const auto& objectPtr : objects) {
        std::vector<char> data = objectPtr->serialize();
        serializedObjects.push_back(data);
    }

    Resume();
}

void BaseLevel::Deserialize() {
    Pause();
    objects.clear();

    int i =0;
    for (const auto& objectPtr : serializedObjects) {
        GameObject* go = new GameObject("d"+i);
        go->deserialize(objectPtr);
        objects.push_back(static_cast<const std::shared_ptr<GameObject>>(go));
        ++i;
    }
    Resume();
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

void BaseLevel::UnLoad() {
    AudioManager::GetInstance().RemoveSound("background");
    AudioManager::GetInstance().RemoveSound("death");
    AudioManager::GetInstance().RemoveSound("fire");
}

void BaseLevel::Start(){
    StartObjects();
    Serialize();
}

void BaseLevel::Pause(){}
void BaseLevel::Resume(){}


void BaseLevel::Update(){

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_SPACE]) {
        Deserialize();
    }

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