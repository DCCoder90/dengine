#include "../../../include/UI/Components/ProgressBarH.h"
#include <SDL.h>
#include "../../../include/System/Game.h"

using namespace dengine;

void ProgressBarH::Render() {
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
    rect.y = std::stoi(GetVar("ypos"));
    rect.x = std::stoi(GetVar("xpos"))+(.2*std::stoi(GetVar("xpos")));
    rect.h = .2*h_ptr;
    rect.w = std::stoi(GetVar("xpos"))*.2;

    //TODO: The math here is messed up, needs to be fixed to render this properly
    SDL_Rect rectt;
    rectt.y = std::stoi(GetVar("ypos"));
    rectt.x = (std::stoi(GetVar("xpos"))-(.2*std::stoi(GetVar("xpos"))))-((h_ptr*.2)-percentage);
    rectt.h = .2*h_ptr;
    rectt.w = (std::stoi(GetVar("xpos"))*.2)-((std::stoi(GetVar("xpos"))*.2)-percentage);

    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

    SDL_UpdateWindowSurface(Game::GetInstance().window);
    SDL_SetRenderDrawColor(renderer, 255, 50, 50, 180);
    SDL_RenderFillRect(renderer,&rectt);
    SDL_SetRenderDrawColor(renderer, 0, 255,0, 180);
    SDL_RenderDrawRect(renderer, &rect);
}