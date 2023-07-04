#include "Packer.h"
using namespace packer;

Packer::Packer(std::string filePath) {
    outFilePath = filePath;
    deleteFileIfExists(outFilePath);
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
    std::vector<char> buffer(size+32);

    std::vector<char> tempBuffer(size);
    if (!file.read(tempBuffer.data(), size)) {
        std::cerr << "Failed to read file: " << filePath << '\n';
    }

    buffer = compressBuffer(tempBuffer);

    std::string extension = filePath.extension().string();
    std::string mimeType = getFileType(extension);
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
    int pos = outFile.tellp();
    std::string tableStartPos = std::to_string(pos-buffer.size());
    tableStartPos.resize(12);

    outFile.close();

    fileLocMap[std::string(filenameChars.begin(), filenameChars.end())] = tableStartPos;
}

void Packer::WriteTable() {
    for (auto& pair : fileLocMap) {
        //The name is 12
        //The size is 12
        //A : is 1
        //So the total amount of Bytes is 25.  WE multiply this by the total number of items
        //in our map and add it to the existing value to get the start position of the file.
        pair.second = std::to_string(std::stoi(pair.second)+fileLocMap.size() * 25);
        pair.second.resize(12);
    }

    std::vector<char> tableData = MapToVector();

    // Read the existing content of the file
    std::ifstream inputFile(outFilePath, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Failed to open input file: " << outFilePath << '\n';
        return;
    }
    std::vector<char> existingData((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    // Write the binary data to a temporary file
    std::string tempFilePath = outFilePath + ".tmp";
    std::ofstream tempFile(tempFilePath, std::ios::binary);
    if (!tempFile) {
        std::cerr << "Failed to open temporary file: " << tempFilePath << '\n';
        return;
    }
    tempFile.write(tableData.data(), tableData.size());

    // Write the existing data to the temporary file
    tempFile.write(existingData.data(), existingData.size());

    // Close the files
    tempFile.close();
    inputFile.close();

    // Replace the original file with the temporary file
    std::filesystem::rename(tempFilePath, outFilePath);
}

std::vector<char> Packer::MapToVector() {
    std::ostringstream oss;
    for (const auto& pair : fileLocMap) {
        oss << pair.first << ':' << pair.second;
    }
    std::string mapString = oss.str();
    std::vector<char> vectorData(mapString.begin(), mapString.end());
    return vectorData;
}

std::string Packer::getFileType(const std::string& extension) {
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

std::vector<char> Packer::compressBuffer(const std::vector<char>& buffer) {
    uLongf compressedSize = compressBound(buffer.size());
    std::vector<char> compressedBuffer(compressedSize);

    if (compress((Bytef*)compressedBuffer.data(), &compressedSize, (const Bytef*)buffer.data(), buffer.size()) != Z_OK) {
        std::cerr << "Failed to compress buffer\n";
        return {};
    }

    compressedBuffer.resize(compressedSize);
    return compressedBuffer;
}

bool Packer::fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

void Packer::deleteFileIfExists(const std::string& filename) {
    if (fileExists(filename)) {
        remove(filename.c_str());
    }
}