//
// Created by ernes on 7/1/2023.
//

#ifndef SDL_LEARN_CAMERA_H
#define SDL_LEARN_CAMERA_H
#include <SDL.h>
#include <string>

class Camera {
public:
    Camera(std::string name, int x, int y, int height, int width);
    Camera(std::string name, int height, int width);
    ~Camera();
    std::string GetName();
    void SetPosition(int x, int y);
private:
    SDL_Rect pos;
    std::string name;
};


#endif //SDL_LEARN_CAMERA_H