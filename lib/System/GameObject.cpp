//
// Created by ernes on 6/24/2023.
//


#include "../../include/System/GameObject.h"
#include "../../include/System/Component.h"

GameObject::GameObject(std::string objectName) {
    name = objectName;
}

std::string GameObject::GetName() {
    return name;
}

bool GameObject::HasComponent(std::string name){
    return std::any_of(components.begin(), components.end(), [&](const auto &item) {
        return item->GetName() == name;
    });
}

void GameObject::AddComponent(Component *component) {
    components.emplace_back(component);
}

void GameObject::RemoveComponent(Component *component) {
    std::remove(components.begin(), components.end(), component);
}

void GameObject::Start() {
    int i;
    for (i = 0; i < components.size(); i++) {
        components[i]->Start();
    }
}

void GameObject::Update() {
    int i;
    for (i = 0; i < components.size(); i++) {
        components[i]->Update();
    }
}

void GameObject::Render() {
    int i;
    for (i = 0; i < components.size(); i++) {
        components[i]->Render();
    }
}

void GameObject::SetPos(float xPos, float yPos) {
    box.x = xPos;
    box.y = yPos;
}