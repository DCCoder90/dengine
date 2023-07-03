#ifndef DENGINE_SPRITESHEET_H
#define DENGINE_SPRITESHEET_H

#include <SDL.h>
#include <SDL_image.h>
#include "../System/Game.h"
#include "../System/Time.h"
#include "../System/Component.h"


namespace dengine {
/**
 * @brief An animation contains information about a specific animation
 * @see SpriteSheet
*/
    class Animation {
    public:
        Animation() : rect({0, 0, 0, 0}), frames(1) {}

        Animation(SDL_Rect rect, int frames) : rect(rect), frames(frames) {}

        SDL_Rect rect;
        int frames;
    };

/**
 * @brief SpriteSheets are used for images that may include multiple depictions or animations
*/
    class SpriteSheet : public Component {
    public:
        /**
     * Create a Spritesheet object
     * @brief Constructor.
     * @param filepath File path to the spritesheet image
     * @param parent The parent object of this spritesheet
     */
        SpriteSheet(std::string filepath, GameObject &parent);

        /**
    * Cleans up and frees resources that were allocated by the spritesheet
    */
        ~SpriteSheet();

        /**
    * Set the current animation to be rendered
         * @param name The name of a registered animation
    */
        void SetCurrentAnimation(std::string name);

        /**
    * Register an animation from a spritesheet
    * @param name Name of the animation
    * @param x The starting x postion of the first frame of the animation
         * @param y The starting y position of the first frame of the animation
         * @param w The width of each frame of the animation
         * @param h The height of each frame of the animation
         * @param frames The total number of frames in the animation
    */
        void RegisterAnimation(std::string name, int x, int y, int w, int h, int frames);

        /**
    * Deregisters an animation, freeing up resources and ensuring animation can no longer be called
    * @param name Name of the animation
    */
        void DeregisterAnimation(std::string name);

        /**
    * Determine if a named animation has already been registered
    * @param name Name of the animation
     * @return Whether the animation exists or not
    */
        bool HasAnimation(std::string name);

        /**
    * Render the animation
    */
        void Render() override;

        /**
    * Pauses the rendering of an animation
    */
        void Pause(bool pause);

    private:
        std::map <std::string, Animation> animationCollection;
        SDL_Texture *sheet;
        std::string currentAnimation = "";
        bool isPaused = false;
    };
}
#endif //DENGINE_SPRITESHEET_H