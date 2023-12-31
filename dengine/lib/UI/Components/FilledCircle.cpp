#include "../../../include/UI/Components/FilledCircle.h"

using namespace dengine_UI;
using namespace dengine;

void FilledCircle::Setup(Vec2 center, int radius){
    centerPoint = center;
    r = radius;
}

void FilledCircle::Update() {}

void FilledCircle::Render() {
    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

    SDL_SetRenderDrawColor(renderer, drawColor.r,drawColor.g,drawColor.b,drawColor.a);

    for (int y = -r; y <= r; ++y) {
        for (int x = -r; x <= r; ++x) {
            if (x * x + y * y <= r * r) {
                SDL_RenderDrawLine(renderer, centerPoint.x + x, centerPoint.y + y, centerPoint.x + x, centerPoint.y + y);
            }
        }
    }
}