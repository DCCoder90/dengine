#include "../../include/UI/UI.h"
#include "../../include/System/Game.h"

using namespace dengine;

UI::UI(){

};

void UI::SetVar(std::string name, std::string value) {
    variables[name]=value;
};

void UI::Update(){

};

void UI::Render() {

    //Below draws a simple heath bar.  Need to add a way to show it depleting
    int w_ptr, h_ptr;
    SDL_GetWindowSize(Game::GetInstance().window,&w_ptr,&h_ptr);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = h_ptr-(.2*h_ptr);
    rect.w = .2*w_ptr;
    rect.h = (1-0)*(.2*h_ptr);

    SDL_Rect rectt;
    rectt.x = 0;
    rectt.y = h_ptr-(1-.2)*(.2*h_ptr);
    rectt.w = .2*w_ptr;
    rectt.h = (1-.2)*(.2*h_ptr);

    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

    SDL_UpdateWindowSurface(Game::GetInstance().window);
    SDL_SetRenderDrawColor(renderer, 255, 50, 50, 180);
    SDL_RenderFillRect(renderer,&rectt);
    SDL_SetRenderDrawColor(renderer, 0, 255,0, 180);
    SDL_RenderDrawRect(renderer, &rect);
};

void UI::Load() {

};