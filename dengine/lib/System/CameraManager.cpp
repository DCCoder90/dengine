#include "../../include/System/CameraManager.h"

using namespace dengine;

CameraManager* CameraManager::instance;

CameraManager& CameraManager::GetInstance() {
    if (instance == nullptr) {
        instance = new CameraManager();
    }
    return *instance;
}

std::shared_ptr<Camera> CameraManager::CreateCamera(std::string name, int x, int y, int height, int width) {
    if(name == MainCamera){
        LOG_CRIT << "MainCamera is created by default.  Only 1 main camera can exist";
        return nullptr;
    }
    cameraCollection[name]=std::make_shared<Camera>(name,x,y,height,width);
    return cameraCollection[name];
}

std::shared_ptr<Camera> CameraManager::GetMainCamera() {
    if(cameraCollection.count(MainCamera) < 1){
        LOG_WARN << "MainCamera does not exist.  Creating it.";
        int w_ptr, h_ptr;
        SDL_GetWindowSize(Game::GetInstance().window,&w_ptr,&h_ptr);
        cameraCollection[MainCamera]=std::make_shared<Camera>(MainCamera,0,0,h_ptr,w_ptr);
    }
    return cameraCollection[MainCamera];
}

std::shared_ptr<Camera> CameraManager::GetCameraByName(std::string cameraName) {
    return cameraCollection[cameraName];
}