//
// Created by ernes on 6/24/2023.
//

#include "../../include/System/Component.h"

Component::Component(std::string componentName){
    name = componentName;
}
std::string Component::GetName(){
    return name;
}