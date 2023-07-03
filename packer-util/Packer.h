#ifndef PACKER_UTIL_PACKER_H
#define PACKER_UTIL_PACKER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <filesystem>
#include <zlib.h>

/**
 * @brief Namespace consisting of the packer utility
 */
namespace packer {
    /**
* @brief Takes care of packing files into a .dat file
*/
    class Packer {
    public:
        /**
        * @brief Create a new packer
         * @param filePath Filepath to the output packed file
        */
        Packer(std::string filePath);
        /**
        * @brief Read a new file into the buffer and write to the packed file
         * @param filePath Filepath of the file to pack
        */
        void ReadFileToBuffer(const std::filesystem::path filePath);

    private:
        /**
        * @brief Perform lossless compression on a buffer using zlib
         * @param buffer The buffer to compress
        */
        std::vector<char> compressBuffer(const std::vector<char> &buffer);

        std::string outFilePath;
        std::vector<char> buffer;

        /**
        * @brief Get a file's type based on file extension
         * @param extension The file's extension
        */
        std::string getFileType(const std::string &extension);
    };
}

#endif //PACKER_UTIL_PACKER_H
