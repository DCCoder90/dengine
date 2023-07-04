//
// Created by ernes on 7/4/2023.
//

#ifndef DENGINE_SERIALIZABLE_H
#define DENGINE_SERIALIZABLE_H

#include <vector>

namespace dengine {
    class Serializable {
    public:
        virtual ~Serializable() {}

        virtual std::vector<char> serialize() const = 0;

        virtual void deserialize(const std::vector<char> &data) = 0;
    };
}

#endif //DENGINE_SERIALIZABLE_H
