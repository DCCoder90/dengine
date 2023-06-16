#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Player/Player.h"
#include "System/Time.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer;
bool isRunning = true;


int main(int argc, char *argv[]) {
    Time time;

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

    Player player;

    while (isRunning) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        if (keystates[SDL_SCANCODE_UP]) {
            player.yPos -= player.speed;
        }
        if (keystates[SDL_SCANCODE_DOWN]) {
            player.yPos += player.speed;
        }
        if (keystates[SDL_SCANCODE_LEFT]) {
            player.xPos -= player.speed;
        }
        if (keystates[SDL_SCANCODE_RIGHT]) {
            player.xPos += player.speed;
        }
        time.StartTick();

        player.posRect.x = player.xPos;
        player.posRect.y = player.yPos;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &player.posRect);

        SDL_RenderPresent(renderer);


        time.EndTick();
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}