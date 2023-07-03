#ifndef PACKER_UTIL_PACKER_H
#define PACKER_UTIL_PACKER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <filesystem>

class Packer {
public:
    Packer(std::string filePath);
    void ReadFileToBuffer(const std::filesystem::path filePath);
private:
    std::string outFilePath;
    std::vector<char> buffer;
    std::string getMimeType(const std::string& extension);
};


#endif //PACKER_UTIL_PACKER_H
