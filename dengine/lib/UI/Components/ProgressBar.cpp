//
// Created by ernes on 7/14/2023.
//

#include "../../../include/UI/Components/ProgressBar.h"
#include <SDL.h>
#include "../../../include/System/Game.h"

void ProgressBar::Render() {
    //Below draws a simple heath bar.  Need to add a way to show it depleting
    int w_ptr, h_ptr;
    SDL_GetWindowSize(Game::GetInstance().window,&w_ptr,&h_ptr);

    int percentage = 1-std::stoi(GetVar("completed"));

    SDL_Rect rect;
    rect.x = std::stoi(GetVar("xpos"));
    rect.y = h_ptr-(.2*h_ptr);
    rect.w = .2*w_ptr;
    rect.h = (1-0)*(.2*h_ptr);

    SDL_Rect rectt;
    rectt.x = std::stoi(GetVar("xpos"));
    rectt.y = h_ptr-(1-.2)*(.2*h_ptr);
    rectt.w = .2*w_ptr;
    rectt.h = (1-std::stoi(GetVar("completed")))*(.2*h_ptr);

    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

    SDL_UpdateWindowSurface(Game::GetInstance().window);
    SDL_SetRenderDrawColor(renderer, 255, 50, 50, 180);
    SDL_RenderFillRect(renderer,&rectt);
    SDL_SetRenderDrawColor(renderer, 0, 255,0, 180);
    SDL_RenderDrawRect(renderer, &rect);
}