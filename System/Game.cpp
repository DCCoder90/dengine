//
// Created by ernes on 6/17/2023.
//

#include "Game.h"
#include <stdio.h>
#include <SDL_image.h>
#include "../Player/Player.h"
#include "Sprite.h"

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
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_UP]) {
        player->yPos -= player->speed;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        player->yPos += player->speed;
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        player->xPos -= player->speed;
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        player->xPos += player->speed;
    }
}
void Game::update(){


    player->posRect.x = player->xPos;
    player->posRect.y = player->yPos;
}
void Game::draw(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,player->texture,NULL,&player->posRect);

    SDL_RenderPresent(renderer);
}
void Game::cleanup(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}
