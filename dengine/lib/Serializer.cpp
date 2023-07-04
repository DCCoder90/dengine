//
// Created by ernes on 7/4/2023.
//

#include "../include/Serializer.h"

using namespace dengine;

Serializer::Serializer(std::string filePath){
    path = filePath;
}

template<typename T>
bool Serializer::saveToFile(const T* obj){
    std::vector<char> objData = serializeObject(obj);
    return saveSerializedObject(objData);
}

template<typename T>
T Serializer::loadFromFile(){
    std::vector<char> objData = loadSerializedData();
    return deserializeData<T>(objData);
}

template <typename T>
std::vector<char> Serializer::serializeObject(const T* obj) {
    std::vector<char> buffer;
    buffer.resize(sizeof(*obj));
    std::memcpy(buffer.data(), obj, sizeof(*obj));
    return buffer;
}

bool Serializer::saveSerializedObject(const std::vector<char>& serializedData) {
    std::ofstream file(path, std::ios::binary);
    if (!file) {
        LOG_CRIT << "Failed to open file: " << path;
        return false;
    }

    // Save serialized object to file
    file.write(serializedData.data(), serializedData.size());
    if (!file) {
        LOG_CRIT << "Failed to write to file: " << path;
        return false;
    }

    LOG_INFO << "Serialized object saved to file: " << path;
    return true;
}

template <typename T>
T Serializer::deserializeData(const std::vector<char>& data) {
    T obj;
    std::memcpy(&obj, data.data(), sizeof(obj));
    return obj;
}

std::vector<char> Serializer::loadSerializedData() {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "Failed to open file: " << path << std::endl;
        return {};
    }

    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(fileSize);
    file.read(buffer.data(), fileSize);
    if (!file) {
        std::cerr << "Failed to read file: " << path << std::endl;
        return {};
    }

    return buffer;
}