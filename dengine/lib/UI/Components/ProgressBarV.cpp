#include "../../../include/UI/Components/ProgressBarV.h"
#include <SDL.h>
#include "../../../include/System/Game.h"

using namespace dengine;

void ProgressBarV::Render() {
    int w_ptr, h_ptr;
    SDL_GetWindowSize(Game::GetInstance().window,&w_ptr,&h_ptr);

    if(!HasVar("ypos")){
        SetVar("ypos",std::to_string(h_ptr));
    }

    if(!HasVar("xpos")){
        SetVar("xpos",std::to_string(w_ptr));
    }

    int percentage = std::stoi(GetVar("completed"));

    SDL_Rect rect;
    rect.x = std::stoi(GetVar("xpos"));
    rect.y = std::stoi(GetVar("ypos"))-(.2*std::stoi(GetVar("ypos")));
    rect.w = .2*w_ptr;
    rect.h = std::stoi(GetVar("ypos"))*.2;

    SDL_Rect rectt;
    rectt.x = std::stoi(GetVar("xpos"));
    rectt.y = (std::stoi(GetVar("ypos"))-(.2*std::stoi(GetVar("ypos"))))+((h_ptr*.2)-percentage);
    rectt.w = .2*w_ptr;
    rectt.h = (std::stoi(GetVar("ypos"))*.2)-((std::stoi(GetVar("ypos"))*.2)-percentage);

    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

    SDL_UpdateWindowSurface(Game::GetInstance().window);
    SDL_SetRenderDrawColor(renderer, 255, 50, 50, 180);
    SDL_RenderFillRect(renderer,&rectt);
    SDL_SetRenderDrawColor(renderer, 0, 255,0, 180);
    SDL_RenderDrawRect(renderer, &rect);
}