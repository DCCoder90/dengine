#ifndef DENGINE_ROUNDEDBOX_H
#define DENGINE_ROUNDEDBOX_H
#include "../UIComponent.h"
#include <SDL.h>
#include <cmath>

using namespace dengine;
class RoundedBox : public  UIComponent{
public:
    void Setup(SDL_Rect rect,double width, int cornerRadius);
    void Render() override;
private:
    SDL_Rect boxRect;
    int cornerR;
    double borderWidth;
};
#endif //DENGINE_ROUNDEDBOX_H
