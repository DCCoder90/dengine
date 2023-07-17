#include "../../../include/UI/Components/HollowRect.h"

using namespace dengine;

void HollowRect::Setup(SDL_Rect rect, int width){
    boxRect = rect;
    borderWidth = width;
}

void HollowRect::Render() {
    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    //Draw the top of the rect
    SDL_Rect rect = {boxRect.x,boxRect.y,boxRect.w,borderWidth};
    SDL_RenderFillRect(renderer,&rect);

    //Draw the bottom side of the rect
    SDL_Rect rectb = {boxRect.x,boxRect.y+boxRect.h,boxRect.w+borderWidth,borderWidth};
    SDL_RenderFillRect(renderer,&rectb);

    //Draw the left side of the rect
    SDL_Rect rectl = {boxRect.x,boxRect.y,borderWidth,boxRect.h};
    SDL_RenderFillRect(renderer,&rectl);

    //Draw the right side of the rect
    SDL_Rect rectr = {boxRect.x+boxRect.w,boxRect.y,borderWidth,boxRect.h};
    SDL_RenderFillRect(renderer,&rectr);
}

