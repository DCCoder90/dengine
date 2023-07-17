#ifndef DENGINE_SERIALIZER_H
#define DENGINE_SERIALIZER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "NanoLog.h"

namespace dengine {
    template<typename T>
    /**
     * @brief A serializer
     * @tparam T The type to serialize or deserialize
     * @deprecated This was initially created for the Load/Save system but I wasn't able to find a way to integrate it just right
     * as such I am marking this as deprecated.  I don't want to get rid of it just yet in case I find a use for it, but currently
     * it isn't used.
     */
    class Serializer {
    public:
        /**
         * Create a new Serializer that will use the file defined in filePath to read/write
         * @brief Constructor
         * @param filePath The path to save to/load from
         */
        Serializer(std::string filePath);

        /**
         * @brief Serialize and object and save it to a file
         * @param obj The object to serialize
         * @return True if success
         */
        bool saveToFile(const T* obj);
        /**
         * @brief Load data from a file and deserialize it back to an object
         * @tparam T The type to deserialize
         * @return The deserialized object
         */
        T loadFromFile();
    private:
    /**
     * @brief File path to save to/load from
     */
        std::string path;
        /**
         * @brief Serialize an object to a vector<char>
         * @tparam T The type of the object to serialize
         * @param obj The object to serialize
         * @return A vector containing the binary of the object
         */
        std::vector<char> serializeObject(const T* obj);
        /**
         * @brief Saves an object to path
         * @param serializedData A vector<char> of serialized data
         * @return True if save was successfull
         * @see path
         */
        bool saveSerializedObject(const std::vector<char>& serializedData);
        /**
         * @brief Loads data from file into a vector<char>
         * @return A vector<char> containing serialized data
         */
        std::vector<char> loadSerializedData();

        /**
         * @brief Deserialize data from a vector back into an object
         * @tparam T The type to deserialize
         * @param data The serialized data to deserialize
         * @return The deserialized object
         */
        T deserializeData(const std::vector<char>& data);
    };


    template<typename T>
    Serializer<T>::Serializer(std::string filePath){
        path = filePath;
    }

    template<typename T>
    bool Serializer<T>::saveToFile(const T* obj){
        std::vector<char> objData = serializeObject(obj);
        return saveSerializedObject(objData);
    }

    template<typename T>
    T Serializer<T>::loadFromFile(){
        std::vector<char> objData = loadSerializedData();
        return deserializeData(objData);
    }

    template <typename T>
    std::vector<char> Serializer<T>::serializeObject(const T* obj) {
        std::vector<char> buffer;
        buffer.resize(sizeof(*obj));
        std::memcpy(buffer.data(), obj, sizeof(*obj));
        return buffer;
    }

    template<typename T>
    bool Serializer<T>::saveSerializedObject(const std::vector<char>& serializedData) {
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
    T Serializer<T>::deserializeData(const std::vector<char>& data) {
        T obj;
        std::memcpy(&obj, data.data(), sizeof(obj));
        return obj;
    }

    template <typename T>
    std::vector<char> Serializer<T>::loadSerializedData() {
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

}



#endif //DENGINE_SERIALIZER_H
