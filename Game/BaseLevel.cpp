//
// Created by ernes on 6/28/2023.
//

#include "BaseLevel.h"
#include "LeafMan.h"

BaseLevel::BaseLevel(){
    GameObject* playerGo = new GameObject("Player");
    Player* player = new Player(*playerGo);
    playerGo->AddComponent(player);
    objects.emplace_back(playerGo);

    for (int i = 0; i < 10; i++) {
        GameObject* enemyGo = new GameObject("Enemy " + i);
        LeafMan* enemy = new LeafMan(*enemyGo);
        enemyGo->AddComponent(enemy);
        objects.emplace_back(enemyGo);
    }


    StartObjects();
}

void BaseLevel::Load(){}
void BaseLevel::Start(){}
void BaseLevel::Pause(){}
void BaseLevel::Resume(){}


void BaseLevel::Update(){
    while(GameState::GetInstance().getGameState() == GAMESTATES::Playing){
        UpdateObjects();
    }
}

void BaseLevel::Render() {
    RenderObjects();
}


void BaseLevel::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
            GameState::GetInstance().setGameState(GAMESTATES::Quit);
        }
    }

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_UP]) {
        player->SetPos(player->xPos, player->yPos -= player->speed);
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        player->SetPos(player->xPos, player->yPos += player->speed);
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        player->SetPos(player->xPos -= player->speed, player->yPos);
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        player->SetPos(player->xPos += player->speed, player->yPos);
    }
}

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

void BaseLevel::draw() {
    SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 255, 255, 255, 255);
    SDL_RenderClear(Game::GetInstance().GetRenderer());


    if (GameState::GetInstance().getGameState() == GAMESTATES::Playing) {
        SDL_RenderCopy(Game::GetInstance().GetRenderer(), player->texture, NULL, &player->posRect);

        for (int i = 0; i < enemies.size(); i++) {
            SDL_RenderCopy(Game::GetInstance().GetRenderer(), enemies[i]->texture, NULL, &enemies[i]->posRect);
        }
    } else if (GameState::GetInstance().getGameState() == GAMESTATES::Gameover) {
        SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 255, 0, 0, 255);
        SDL_RenderClear(Game::GetInstance().GetRenderer());
    }


    SDL_RenderPresent(Game::GetInstance().GetRenderer());
}