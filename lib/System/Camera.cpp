#include "../../include/System/Camera.h"

Camera::Camera(std::string name, int x, int y, int height, int width) {
    this->name = name;
    pos = {x,y,width,height};
}

Camera::Camera(std::string name,int height, int width) {
    this->name = name;
    pos = {0,0,width, height};
}

void Camera::SetPosition(int x, int y) {
    pos.x = x;
    pos.y = y;
}

std::string Camera::GetName() {
    return name;
}