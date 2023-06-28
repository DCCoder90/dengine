//
// Created by ernes on 6/24/2023.
//


#include "../../include/System/GameObject.h"


GameObject::GameObject(std::string objectName){
    name = objectName;
}

std::string GameObject::GetName() {
    return name;
}

void GameObject::AddComponent(Component* component){
    components.emplace_back(component);
}

void GameObject::RemoveComponent(Component* component){
    std::remove(components.begin(),components.end(),component);
}

void GameObject::Start(){
    int i;
    for(i = 0;i<components.size();i++){
        components[i]->Start();
    }
}

void GameObject::Update(){
    int i;
    for(i = 0;i<components.size();i++){
        components[i]->Update();
    }
}