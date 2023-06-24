//
// Created by ernes on 6/17/2023.
//

#include "../../include/System/Game.h"

Game::Game(){
    isRunning = true;
    player = new Player();
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
        isRunning = false;
    }

    if(IMG_Init(IMG_INIT_PNG) < 0){
        printf("SDL could not initialize images! SDL_ERROR: %s\n",IMG_GetError());
        isRunning = false;
    }


    window = SDL_CreateWindow("Main Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
        printf("Renderer not initialize! SDL_ERROR: %s\n", SDL_GetError());
        isRunning = false;
    }

    if (window == NULL) {
        printf("Window could not be created! SDL_ERROR: %s\n", SDL_GetError());
        isRunning = false;
    }

    Sprite sprite = Sprite("../Assets/circle.png", renderer);
    player->texture = sprite.getTexture();


    Sprite enemySprite = Sprite("../Assets/evil.png", renderer);
    for(int i =0;i<10;i++){
        Enemy* e = new Enemy;
        e->SetPos(40.f*i,40.f*i);
        e->texture = enemySprite.getTexture();
        enemies.emplace_back(e);
    }
}

void Game::loop(){
    while(isRunning){
        time.StartTick();
        handleEvents();
        update();
        draw();
        time.EndTick();
    }

    cleanup();

}
void Game::handleEvents(){
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
            isRunning = false;
        }
    }

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_UP]) {
        player->SetPos(player->xPos,player->yPos -=player->speed);
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        player->SetPos(player->xPos,player->yPos +=player->speed);
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        player->SetPos(player->xPos -= player->speed,player->yPos);
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        player->SetPos(player->xPos += player->speed,player->yPos);
    }
}
void Game::update(){
    //Update loop

    //Move enemies towards player
    for(int i=0;i<enemies.size();i++){
        if(enemies[i]->xPos < player->xPos){
            enemies[i]->SetPos(enemies[i]->xPos+enemies[i]->speed,enemies[i]->yPos);
        }
        if(enemies[i]->xPos > player->xPos){
            enemies[i]->SetPos(enemies[i]->xPos-enemies[i]->speed,enemies[i]->yPos);
        }
        if(enemies[i]->yPos < player->yPos){
            enemies[i]->SetPos(enemies[i]->xPos,enemies[i]->yPos+enemies[i]->speed);
        }
        if(enemies[i]->yPos > player->yPos){
            enemies[i]->SetPos(enemies[i]->xPos,enemies[i]->yPos-enemies[i]->speed);
        }

        //Check enemy collision

        //Just a simple collision that will be able to tell if right or bottom side of
        //enemy touches player or if enemy is fully on top of player.   Need to fix
        //this though so we only check if we know for sure player and enemy are near each other.
        if(enemies[i]->xPos+enemies[i]->posRect.w >= player ->xPos &&
        enemies[i]->xPos <= player->xPos+player->posRect.w &&
        enemies[i]->yPos+enemies[i]->posRect.h >= player ->yPos &&
        enemies[i]->yPos <= player->yPos+player->posRect.h){
            gameState = GAMESTATES::Gameover;
        }
    }


}

void Game::draw(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);


    if(gameState == GAMESTATES::Playing){
        SDL_RenderCopy(renderer,player->texture,NULL,&player->posRect);

        for(int i=0;i<enemies.size();i++){
            SDL_RenderCopy(renderer,enemies[i]->texture,NULL,&enemies[i]->posRect);
        }
    }else if (gameState == GAMESTATES::Gameover){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);
    }


    SDL_RenderPresent(renderer);
}
void Game::cleanup(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}
