#include "../../include/UI/UIComponent.h"

using namespace dengine_UI;

void UIComponent::SetVar(std::string key, std::string value) {
    variables[key]=value;
}

bool UIComponent::HasVar(std::string key) {
    return variables.count(key) > 0;
}

std::string UIComponent::GetVar(std::string key) {
    return variables[key];
}