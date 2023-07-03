#ifndef PACKER_UTIL_PACKER_H
#define PACKER_UTIL_PACKER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <filesystem>
#include <zlib.h>

class Packer {
public:
    Packer(std::string filePath);
    void ReadFileToBuffer(const std::filesystem::path filePath);
private:
    std::vector<char> compressBuffer(const std::vector<char>& buffer);
    std::string outFilePath;
    std::vector<char> buffer;
    std::string getFileType(const std::string& extension);
};


#endif //PACKER_UTIL_PACKER_H
