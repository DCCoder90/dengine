//
// Created by ernes on 7/3/2023.
//

#ifndef PACKER_UTIL_CLIARG_H
#define PACKER_UTIL_CLIARG_H

#include <algorithm>
#include <string>

class CLIArg {
public:
    CLIArg();
    int GetIndexOfArgument(char* argv[], std::string argument);
    bool ArgumentExists(char* argv[], std::string argument);
};


#endif //PACKER_UTIL_CLIARG_H
