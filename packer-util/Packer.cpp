#include "Packer.h"

Packer::Packer(std::string filePath) {
    outFilePath = filePath;
}

void Packer::ReadFileToBuffer(const std::filesystem::path filePath){
    buffer.clear();
    std::string fileee = filePath.string();
    std::ifstream file(filePath.string(), std::ios::binary);

    if (!file) {
        std::cerr << "Failed to open file: " << filePath << '\n';
    }

    // Get the size of the file
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    // Read the file into a vector
    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size)) {
        std::cerr << "Failed to read file: " << filePath << '\n';
    }

    std::string extension = filePath.extension().string();
    std::string mimeType = getMimeType(extension);
    mimeType.resize(8, ' ');
    std::vector<char> mimeTypeChars(mimeType.begin(), mimeType.end());
    buffer.insert(buffer.begin(), mimeTypeChars.begin(), mimeTypeChars.end());

    std::string sizeStr = std::to_string(size);
    sizeStr.resize(12, ' ');
    std::vector<char> sizeChars(sizeStr.begin(), sizeStr.end());
    buffer.insert(buffer.begin() + mimeTypeChars.size(), sizeChars.begin(), sizeChars.end());

    std::string filename = filePath.stem().string();
    filename.resize(12, ' ');
    std::vector<char> filenameChars(filename.begin(), filename.end());
    buffer.insert(buffer.begin(), filenameChars.begin(), filenameChars.end());

    std::ofstream outFile(outFilePath, std::ios::binary | std::ios::app | std::ios::out);
    if (!outFile) {
        std::cerr << "Failed to open output file "<< filePath <<" \n";
    }
    outFile.write(buffer.data(), buffer.size());
}

std::string Packer::getMimeType(const std::string& extension) {
    static std::map<std::string, std::string> mimeTypes = {
            {".txt", "text"},
            {".png", "png"},
            {".wav","wav"}
    };

    auto it = mimeTypes.find(extension);
    if (it != mimeTypes.end()) {
        return it->second;
    } else {
        std::cerr << "Unable to determine mimetype\n";
    }
}
