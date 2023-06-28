//
// Created by ernes on 6/17/2023.
//

#ifndef SDL_LEARN_SPRITE_H
#define SDL_LEARN_SPRITE_H

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

class Sprite {
public:
    /**
 *  GameState is used to manage the current state of the game as a whole.  A few game states that are built in
 *  reference whether the game is currently being played, at the gameover screen, or at the flash screen.
     *  @param filepath The filepath of the sprite
     *  @param renderer The renderer that will utilize this sprite
 */
    Sprite(std::string filepath, SDL_Renderer *renderer);

    /**
 *  Returns the texture
 */
    SDL_Texture *getTexture();

private:
    /**
 *  Texture of the sprite
 */
    SDL_Texture *texture;
};


#endif //SDL_LEARN_SPRITE_H
