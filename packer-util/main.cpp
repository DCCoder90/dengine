#include <iostream>
#include <algorithm>
#include <filesystem>
#include "Packer.h"
#include "CLIArg.h"

using namespace packer;

int main(int argc, char* argv[]) {
    CLIArg* cli = new CLIArg();
    if(!cli->ArgumentExists(argv,"-d")){
        throw std::runtime_error("A directory must be defined");
    }

    if(!cli->ArgumentExists(argv,"-f")){
        throw std::runtime_error("An output file must be defined");
    }

    int outputIndex = cli->GetIndexOfArgument(argv,"-f");

    Packer* packer = new Packer(argv[outputIndex]);

    int directoryIndex = cli->GetIndexOfArgument(argv,"-d");

    for (const auto& entry : std::filesystem::directory_iterator(argv[directoryIndex])) {
        packer->ReadFileToBuffer(entry.path());
    }

    return 0;
}

