#include "../../include/System/GameObject.h"
#include "../../include/System/Component.h"
#include "../../include/Components/Collider.h"
#include "../../include/Components/SpriteSheet.h"

using namespace dengine;

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

std::weak_ptr<Component> GameObject::GetComponentByName(std::string name) {
    if(HasComponent(name)){
        for(int i=0;i<components.size();i++){
            if(components[i]->GetName() == name) {
                return std::make_shared<Component>(*components[i]);
            }
        }
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

void GameObject::NotifyCollision(GameObject& other){
    int i;
    for (i = 0; i < components.size(); i++) {
        components[i]->NotifyCollision(other);
    }
}