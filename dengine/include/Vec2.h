#ifndef SDL_LEARN_VEC2_H
#define SDL_LEARN_VEC2_H

/**
 * @brief A vector composed of two points
 */
class Vec2 {
public:
    /**
 * @brief Create a new Vec2
 */
    Vec2();

    /**
 * @brief Create a new Vec2 at the specified points
     * @param x The x position of the vector
     * @param y The y position of the vector
 */
    Vec2(float x, float y);

    /**
* @brief X position of the vector
*/
    float x;
    /**
* @brief Y position of the vector
*/
    float y;
};


#endif //SDL_LEARN_VEC2_H
