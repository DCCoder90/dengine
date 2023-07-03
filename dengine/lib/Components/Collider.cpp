#include "../../include/Components/Collider.h"

using namespace dengine;

Collider::Collider(GameObject &associated, Vec2 scale, Vec2 offset) : Component(associated), scale(scale),
                                                                      offset(offset) {
}

void Collider::Update() {
    box = parent.box;
    box.x = scale.x - box.w / 2;
    box.y = scale.y - box.h / 2;
}