//
// Created by ernes on 7/6/2023.
//

#ifndef DENGINE_HUD_H
#define DENGINE_HUD_H

#include "../include/System/Component.h"
#include <RmlUi/Core/ElementDocument.h>
#include "../include/System/Game.h"
using namespace dengine;

namespace DemoGame {
    class Hud : public Component {
    public:
        /**
    * Creates a sprite object
    */
        Hud(dengine::GameObject &parent);

        /**
    * Frees up resources allocated by Sprite
    */
        ~Hud();

        /**
    * Renders the HUD
    */
        void Render() override;

    private:
        Rml::ElementDocument* document;
    };
}

#endif //DENGINE_HUD_H
