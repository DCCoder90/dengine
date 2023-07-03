#ifndef DENGINE_CAMERAMANAGER_H
#define DENGINE_CAMERAMANAGER_H
#include "Camera.h"
#include <string>
#include <map>
#include <memory>
#include "Game.h"
#include "../Universal.h"

namespace dengine {
    class CameraManager {
    public:
        std::shared_ptr <Camera> GetCameraByName(std::string cameraName);

        std::shared_ptr <Camera> CreateCamera(std::string name, int x, int y, int height, int width);

        std::shared_ptr <Camera> GetMainCamera();

        bool CameraExists(std::string cameraName); //TODO: Implement this
        static CameraManager &GetInstance();

    private:
        const std::string MainCamera = "MainCamera";
        static CameraManager *instance;
        std::map <std::string, std::shared_ptr<Camera>> cameraCollection;
    };
}

#endif //DENGINE_CAMERAMANAGER_H
