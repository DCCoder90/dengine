//
// Created by ernes on 7/6/2023.
//

#ifndef DENGINE_HUD_H
#define DENGINE_HUD_H

#include "../include/System/Component.h"

using namespace dengine;

namespace DemoGame {
    class hud : public Component {
        /**
    * Creates a sprite object
    */
        hud(std::string filepath, GameObject &parent);

        /**
    * Frees up resources allocated by Sprite
    */
        ~hud();

        /**
    * Renders the HUD
    */
        void Render() override;
    };
}

#endif //DENGINE_HUD_H
