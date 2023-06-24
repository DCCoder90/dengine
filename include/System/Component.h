//
// Created by ernes on 6/24/2023.
//

#ifndef SDL_LEARN_COMPONENT_H
#define SDL_LEARN_COMPONENT_H

#include <string>

class Component {
public:
    Component(std::string componentName);
    std::string GetName();
    virtual void Update();
private:
    std::string name;
};


#endif //SDL_LEARN_COMPONENT_H
