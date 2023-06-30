//
// Created by ernes on 6/29/2023.
//

#include <iostream>
#include <algorithm>

template <typename T, typename Iterator>
bool containsType(Iterator begin, Iterator end) {
    return std::any_of(begin, end, [](const auto& item) {
        using ItemType = std::remove_reference_t<std::remove_pointer_t<decltype(item)>>;
        return dynamic_cast<const T*>(static_cast<const ItemType*>(item)) != nullptr;
    });
}