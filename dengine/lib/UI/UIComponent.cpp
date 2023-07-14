#include "../../include/UI/UIComponent.h"

using namespace dengine;

void UIComponent::SetVar(std::string key, std::string value) {
    variables[key]=value;
}

std::string UIComponent::GetVar(std::string key) {
    return variables[key];
}