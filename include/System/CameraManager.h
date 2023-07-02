#ifndef SDL_LEARN_CAMERAMANAGER_H
#define SDL_LEARN_CAMERAMANAGER_H
#include "Camera.h"
#include <string>
#include <map>
#include <memory>
#include "Game.h"

class CameraManager {
public:
    std::shared_ptr<Camera> GetCameraByName(std::string cameraName);
    std::shared_ptr<Camera> CreateCamera(std::string name, int x, int y, int height, int width);
    std::shared_ptr<Camera> GetMainCamera();
    bool CameraExists(std::string cameraName);
    static CameraManager& GetInstance();
private:
    const std::string MainCamera = "MainCamera";
    static CameraManager* instance;
    std::map<std::string, std::shared_ptr<Camera>> cameraCollection;
};


#endif //SDL_LEARN_CAMERAMANAGER_H
