//
// Created by ernes on 7/14/2023.
//

#ifndef DENGINE_UICOMPONENT_H
#define DENGINE_UICOMPONENT_H
#include <map>
#include <string>
namespace dengine {
    class UIComponent {
    public:
        virtual void Render() = 0;
        void SetVar(std::string key,std::string value);
        bool HasVar(std::string key);
    protected:
        std::string GetVar(std::string key);
    private:
        std::map<std::string,std::string> variables;
    };
};

#endif //DENGINE_UICOMPONENT_H
