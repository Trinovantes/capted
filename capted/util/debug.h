#pragma once

#include "../StringDataNode.h"
#include "../InputParser.h"

#include <iostream>
using std::cerr;
using std::endl;

namespace capted {

typedef std::pair<int, int> IntPair;

//------------------------------------------------------------------------------
// Default
//------------------------------------------------------------------------------

template<typename T>
std::string arrayToString(std::vector<T> array) {
    std::stringstream ss;
    ss << "[";

    for (int i = 0; i < array.size(); i++) {
        if (i > 0) {
            ss << ", ";
        }

        ss << array[i];
    }

    ss << "]";
    return ss.str();
}

//------------------------------------------------------------------------------
// Boolean array
//------------------------------------------------------------------------------

template<>
std::string arrayToString(std::vector<bool> array) {
    std::stringstream ss;
    ss << "[";

    for (int i = 0; i < array.size(); i++) {
        if (i > 0) {
            ss << ", ";
        }

        if (array[i]) {
            ss << "true";
        } else {
            ss << "false";
        }
    }

    ss << "]";
    return ss.str();
}

//------------------------------------------------------------------------------
// Nested int array
//------------------------------------------------------------------------------

template<typename T>
std::string arrayToString(std::vector<typename std::vector<T>> nestedArray) {
    std::stringstream ss;
    ss << "[";

    for (int i = 0; i < nestedArray.size(); i++) {
        if (i > 0) {
            ss << ", ";
        }

        ss << arrayToString(nestedArray[i]);
    }

    ss << "]";
    return ss.str();
}

//------------------------------------------------------------------------------
// String node array
//------------------------------------------------------------------------------

template<>
std::string arrayToString<Node<StringNodeData>*>(std::vector<Node<StringNodeData>*> array) {
    std::stringstream ss;
    ss << "[";

    for (int i = 0; i < array.size(); i++) {
        if (i > 0) {
            ss << ", ";
        }

        ss << *array[i];
    }

    ss << "]";
    return ss.str();
}

//------------------------------------------------------------------------------
// Mappings
//------------------------------------------------------------------------------

template<>
std::string arrayToString(std::vector<IntPair> mappings) {
    std::stringstream ss;
    ss << "[";

    for (int i = 0; i < mappings.size(); i++) {
        if (i > 0) {
            ss << ", ";
        }

        ss << mappings[i].first << ":" << mappings[i].second;
    }

    ss << "]" << endl;
    return ss.str();
}

} // namespace capted
