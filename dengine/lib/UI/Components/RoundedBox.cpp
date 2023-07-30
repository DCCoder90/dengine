#include "../../../include/UI/Components/RoundedBox.h"
#include "../../../include/System/Game.h"

using namespace dengine_UI;
using namespace dengine;

void RoundedBox::Update() {}

void RoundedBox::Render() {
    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

    // Set the desired render draw color
    SDL_SetRenderDrawColor(renderer, drawColor.r,drawColor.g,drawColor.b,drawColor.a);

    // Draw outer border
    SDL_Point outerBorderPoints[16];
    outerBorderPoints[0] = {boxRect.x + cornerR, boxRect.y};
    outerBorderPoints[1] = {boxRect.x + boxRect.w - cornerR, boxRect.y};
    outerBorderPoints[2] = {boxRect.x + boxRect.w, boxRect.y + cornerR};
    outerBorderPoints[3] = {boxRect.x + boxRect.w, boxRect.y + boxRect.h - cornerR};
    outerBorderPoints[4] = {boxRect.x + boxRect.w - cornerR, boxRect.y + boxRect.h};
    outerBorderPoints[5] = {boxRect.x + cornerR, boxRect.y + boxRect.h};
    outerBorderPoints[6] = {boxRect.x, boxRect.y + boxRect.h - cornerR};
    outerBorderPoints[7] = {boxRect.x, boxRect.y + cornerR};

    for (int i = 0; i < 8; ++i) {
        outerBorderPoints[i + 8] = outerBorderPoints[i];
        outerBorderPoints[i + 8].x += borderWidth;
        outerBorderPoints[i + 8].y += borderWidth;
    }

    SDL_RenderDrawLines(renderer, outerBorderPoints, 16);

    // Draw inner border
    SDL_Point innerBorderPoints[16];
    for (int i = 0; i < 16; ++i) {
        innerBorderPoints[i] = outerBorderPoints[i];
        innerBorderPoints[i].x -= borderWidth;
        innerBorderPoints[i].y -= borderWidth;
    }

    SDL_RenderDrawLines(renderer, innerBorderPoints, 16);

    // Draw top-left corner
    for (int i = 0; i < cornerR; ++i) {
        int xPos = boxRect.x + cornerR - i;
        int yPos = boxRect.y + cornerR - i;
        SDL_RenderDrawPoint(renderer, xPos, yPos);
        SDL_RenderDrawPoint(renderer, xPos, yPos + boxRect.h - cornerR * 2);
    }

    // Draw top-right corner
    for (int i = 0; i < cornerR; ++i) {
        int xPos = boxRect.x + boxRect.w - cornerR + i;
        int yPos = boxRect.y + cornerR - i;
        SDL_RenderDrawPoint(renderer, xPos, yPos);
        SDL_RenderDrawPoint(renderer, xPos, yPos + boxRect.h - cornerR * 2);
    }

    // Draw bottom-left corner
    for (int i = 0; i < cornerR; ++i) {
        int xPos = boxRect.x + cornerR - i;
        int yPos = boxRect.y + boxRect.h - cornerR + i;
        SDL_RenderDrawPoint(renderer, xPos, yPos);
        SDL_RenderDrawPoint(renderer, xPos, yPos - boxRect.h + cornerR * 2);
    }

    // Draw bottom-right corner
    for (int i = 0; i < cornerR; ++i) {
        int xPos = boxRect.x + boxRect.w - cornerR + i;
        int yPos = boxRect.y + boxRect.h - cornerR + i;
        SDL_RenderDrawPoint(renderer, xPos, yPos);
        SDL_RenderDrawPoint(renderer, xPos, yPos - boxRect.h + cornerR * 2);
    }
}

void RoundedBox::Setup(SDL_Rect rect,double width, int cornerRadius){
    boxRect = rect;
    cornerR = cornerRadius;
    borderWidth = width;
}