#ifndef DENGINE_CIRCLE_H
#define DENGINE_CIRCLE_H
#include "../UIComponent.h"
#include <SDL.h>
#include <cmath>
#include "../../System/Game.h"
#include "../../Vec2.h"

namespace dengine {
    class Circle : public UIComponent{
    public:
        void Setup(Vec2 center, int radius);

        void Render() override;

    private:
        Vec2 centerPoint;
        int r;
    };
}

#endif //DENGINE_CIRCLE_H
