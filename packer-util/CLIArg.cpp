//
// Created by ernes on 7/3/2023.
//

#include "CLIArg.h"

using namespace packer;

CLIArg::CLIArg() {}

int CLIArg::GetIndexOfArgument(char* argv[], std::string argument) {
    int n = sizeof(argv);//sizeof(argv[0]);
    auto itr = std::find(argv, argv + n, argument);
    return std::distance(argv,itr)+1;
}

bool CLIArg::ArgumentExists(char* argv[], std::string argument){
    int n = sizeof(argv)/sizeof(argv[0]);
    auto itr = std::find(argv, argv + n, argument);
    return std::distance(argv,itr) > 0;
}