#include "../../../include/UI/Components/Circle.h"

using namespace dengine_UI;
using namespace dengine;

void Circle::Setup(Vec2 center, int radius){
    centerPoint = center;
    r = radius;
}

void Circle::Render() {
    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

    SDL_SetRenderDrawColor(renderer, 255, 0, 50, 255);

    int x = r - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (r << 1);

    while (x >= y) {
        SDL_RenderDrawPoint(renderer, centerPoint.x + x, centerPoint.y + y);
        SDL_RenderDrawPoint(renderer, centerPoint.x + y, centerPoint.y + x);
        SDL_RenderDrawPoint(renderer, centerPoint.x - y, centerPoint.y + x);
        SDL_RenderDrawPoint(renderer, centerPoint.x - x, centerPoint.y + y);
        SDL_RenderDrawPoint(renderer, centerPoint.x - x, centerPoint.y - y);
        SDL_RenderDrawPoint(renderer, centerPoint.x - y, centerPoint.y - x);
        SDL_RenderDrawPoint(renderer, centerPoint.x + y, centerPoint.y - x);
        SDL_RenderDrawPoint(renderer, centerPoint.x + x, centerPoint.y - y);

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (r << 1);
        }
    }
}