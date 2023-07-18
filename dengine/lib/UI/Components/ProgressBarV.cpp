#include "../../../include/UI/Components/ProgressBarV.h"
#include <SDL.h>
#include "../../../include/System/Game.h"

using namespace dengine_UI;
using namespace dengine;

void ProgressBarV::Render() {
    int w_ptr, h_ptr;
    SDL_GetWindowSize(Game::GetInstance().window,&w_ptr,&h_ptr);

    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y-(.2*position.y);
    rect.w = .2*w_ptr;
    rect.h = position.y*.2;

    SDL_Rect rectt;
    rectt.x = position.x;
    rectt.y = (position.y-(.2*position.y))+((h_ptr*.2)-completed);
    rectt.w = .2*w_ptr;
    rectt.h = (position.y*.2)-((position.y*.2)-completed);

    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

    SDL_UpdateWindowSurface(Game::GetInstance().window);
    SDL_SetRenderDrawColor(renderer, fillColor.r,fillColor.g,fillColor.b,fillColor.a);

    SDL_RenderFillRect(renderer,&rectt);
    SDL_SetRenderDrawColor(renderer, drawColor.r,drawColor.g,drawColor.b,drawColor.a);
    SDL_RenderDrawRect(renderer, &rect);
}