//
// Created by ernes on 7/4/2023.
//

#ifndef DENGINE_SERIALIZER_H
#define DENGINE_SERIALIZER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "../include/Utils/NanoLog.h"

namespace dengine {
    class Serializer {
    public:
        /**
         * @brief Create a new Serializer
         * @param filePath The path to save to/load from
         */
        Serializer(std::string filePath);
        template<typename T>
        /**
         * @brief Serialize and object and save it to a file
         * @tparam T The type to serialize
         * @param obj The object to serialize
         * @return True if success
         */
        bool saveToFile(const T* obj);
        template<typename T>
        /**
         * @brief Load data from a file and deserialize it back to an object
         * @tparam T The type to deserialize
         * @return The deserialized object
         */
        T loadFromFile();
    private
    /**
     * @brief File path to save to/load from
     */
        std::string path;
        template <typename T>
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
        template <typename T>
        /**
         * @brief Deserialize data from a vector back into an object
         * @tparam T The type to deserialize
         * @param data The serialized data to deserialize
         * @return The deserialized object
         */
        T deserializeData(const std::vector<char>& data);
    };
}

#endif //DENGINE_SERIALIZER_H
