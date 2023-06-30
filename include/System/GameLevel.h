//
// Created by ernes on 6/28/2023.
//

#ifndef SDL_LEARN_GAMELEVEL_H
#define SDL_LEARN_GAMELEVEL_H


#include "GameObject.h"
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>
class GameLevel {
public:
    GameLevel();

    virtual ~GameLevel();

    virtual void Load() = 0;

    virtual void Update() = 0;

    virtual void Render() = 0;

    virtual void Start() = 0;

    virtual void Pause() = 0;

    virtual void Resume() = 0;

    virtual std::weak_ptr<GameObject> AddObject(GameObject* go);

    virtual std::weak_ptr<GameObject> GetObject(GameObject* go);

    virtual std::weak_ptr<GameObject> GetObjectByComponent(std::string componentName);
protected:
    void StartObjects();

    virtual void UpdateObjects();
    virtual void RenderObjects();

    bool started;
    std::vector<std::shared_ptr<GameObject>> objects;
    std::vector<std::shared_ptr<GameObject>> newObjects;
};


#endif //SDL_LEARN_GAMELEVEL_H
