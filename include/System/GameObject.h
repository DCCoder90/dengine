//
// Created by ernes on 6/24/2023.
//

#ifndef SDL_LEARN_GAMEOBJECT_H
#define SDL_LEARN_GAMEOBJECT_H

#include <string>
#include <vector>
#include "Component.h"
#include<bits/stdc++.h>

class GameObject {
public:
    GameObject(std::string objectName);
    std::string GetName();
    void AddComponent(Component* component);
    void RemoveComponent(Component* component);
    void Update();
private:
    std::vector<class Component*> components;
    std::string name;
};


#endif //SDL_LEARN_GAMEOBJECT_H
