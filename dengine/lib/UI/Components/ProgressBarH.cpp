#include "../../../include/UI/Components/ProgressBarH.h"
#include <SDL.h>
#include "../../../include/System/Game.h"

using namespace dengine_UI;
using namespace dengine;

void ProgressBarH::Render() {
    int w_ptr, h_ptr;
    SDL_GetWindowSize(Game::GetInstance().window,&w_ptr,&h_ptr);

    SDL_Rect rect;
    rect.y = position.y;
    rect.x = position.x+(.2*position.x);
    rect.h = .2*h_ptr;
    rect.w = position.x*.2;

    //TODO: The math here is messed up, needs to be fixed to render this properly
    SDL_Rect rectt;
    rectt.y = position.y;
    rectt.x = (position.x-(.2*position.x))-((h_ptr*.2)-completed);
    rectt.h = .2*h_ptr;
    rectt.w = (position.x*.2)-((position.x*.2)-completed);

    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

    SDL_UpdateWindowSurface(Game::GetInstance().window);
    SDL_SetRenderDrawColor(renderer, fillColor.r,fillColor.g,fillColor.b,fillColor.a);

    SDL_RenderFillRect(renderer,&rectt);
    SDL_SetRenderDrawColor(renderer, drawColor.r,drawColor.g,drawColor.b,drawColor.a);
    SDL_RenderDrawRect(renderer, &rect);
}