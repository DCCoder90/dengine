//Help from https://github.com/mikaelmello/sdl-game-engine
#include "../../include/System/GameLevel.h"
#include "../../include/System/Game.h"

using namespace dengine;

GameLevel::GameLevel() : started(false) {}

GameLevel::~GameLevel() {
    objects.clear();
    newObjects.clear();
}

std::weak_ptr<GameObject> GameLevel::AddObject(GameObject* go) {
    std::shared_ptr<GameObject> goSharedPtr(go);
    newObjects.push_back(goSharedPtr);

    if (started) {
        goSharedPtr->Start();
    }

    return std::weak_ptr<GameObject>(goSharedPtr);
}

std::weak_ptr<GameObject> GameLevel::GetObjectByComponent(std::string componentName){
    auto it = std::find_if(objects.begin(), objects.end(),
                           [&](std::shared_ptr<GameObject>& go2){

        return go2->HasComponent(componentName); });

    if (it == objects.end()) {
        throw std::runtime_error("Cannot get object that doesn't contain component");
    }

    return std::weak_ptr<GameObject>(*it);
}

std::weak_ptr<GameObject> GameLevel::GetObject(std::string gameObjectName) {
    auto it = std::find_if(objects.begin(), objects.end(),
                           [&](std::shared_ptr<GameObject>& go2){ return gameObjectName == go2.get()->GetName(); });

    if (it == objects.end()) {
        return std::weak_ptr<GameObject>();
    }

    return std::weak_ptr<GameObject>(*it);
}

void GameLevel::StartObjects() {
    std::for_each(
            objects.begin(),
            objects.end(),
            [&](std::shared_ptr<GameObject>& go) { go->Start(); }
    );
}

void GameLevel::UpdateObjects() {


    objects.insert(objects.end(), newObjects.begin(), newObjects.end());
    newObjects.clear();

    std::for_each(
            objects.begin(),
            objects.end(),
            [&](std::shared_ptr<GameObject>& go) { go->Update(); }
    );
}

void GameLevel::RenderObjects() {
    std::for_each(
            objects.begin(),
            objects.end(),
            [](std::shared_ptr<GameObject>& go) { go->Render(); }
    );
}