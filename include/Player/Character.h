//
// Created by ernes on 6/20/2023.
//

#ifndef SDL_LEARN_CHARACTER_H
#define SDL_LEARN_CHARACTER_H

#include <SDL.h>
#include <SDL_image.h>

class Character {
public:
    /**
 * Current x Position of the character based on position on the screen
 */
    float xPos;
    /**
* Current y Position of the character based on position on the screen
*/
    float yPos;
    /**
 * A rect containing xPos,yPos,height, and width of the character
     * @see xPos
     * @see yPos
 */
    SDL_Rect posRect;
    /**
 * An int containing the speed of the character
 */
    int speed;
    SDL_Texture *texture;

    /**
 * Sets the position of the character on the screen
 */
    void SetPos(float xPos, float yPos);
};


#endif //SDL_LEARN_CHARACTER_H
