//
// Created by ernes on 7/1/2023.
//

#ifndef DENGINE_CAMERA_H
#define DENGINE_CAMERA_H
#include <SDL.h>
#include <string>

namespace dengine {
    /**
     * The camera is meant to be used as a view point for the player or user of the application.  This allows the scene to focus on
     * different aspects of the environment or different viewpoints of the character.
     * @brief A camera
     */
    class Camera {
    public:
        /**
         * Create a new camera with x,y coordinates
         * @brief Constructor
         * @param name The name of the camera
         * @param x The X coordinate of the camera
         * @param y The Y coordinate of the camera
         * @param height The height of the viewport
         * @param width The width of the viewport
         * @see Camera(std::string name, int height, int width)
         */
        Camera(std::string name, int x, int y, int height, int width);

        /**
         * Create a new camera with default x and y coordinates
         * @brief Constructor
         * @param name The name of the camera
         * @param height The height of the viewport
         * @param width The width of the viewport
         */
        Camera(std::string name, int height, int width);

        /**
         * @brief Get Camera Name
         * @return Camera name
         */
        std::string GetName();

        /**
         * @brief Set camera position
         * @param x X coordinate
         * @param y Y coordinate
         */
        void SetPosition(int x, int y);

    private:
        SDL_Rect pos;
        std::string name;
    };
}

#endif //DENGINE_CAMERA_H