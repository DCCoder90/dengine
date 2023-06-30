//
// Created by ernes on 6/28/2023.
//

#include "BaseLevel.h"
#include "LeafMan.h"

BaseLevel::BaseLevel(){
}

void BaseLevel::Load(){}
void BaseLevel::Start(){
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

    StartObjects();
}
void BaseLevel::Pause(){}
void BaseLevel::Resume(){}


void BaseLevel::Update(){
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