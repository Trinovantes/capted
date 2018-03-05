#pragma once

#include "../StringNodeData.h"
#include "../InputParser.h"
#include <iostream>

namespace capted {

//------------------------------------------------------------------------------
// arrayToString
//------------------------------------------------------------------------------

template<typename T>
std::string arrayToString(std::vector<T> array);

//------------------------------------------------------------------------------
// arrayToString bool
//------------------------------------------------------------------------------

template<>
std::string arrayToString(std::vector<bool> array);

//------------------------------------------------------------------------------
// arrayToString nested
//------------------------------------------------------------------------------

template<typename T>
std::string arrayToString(std::vector<typename std::vector<T>> nestedArray);

//------------------------------------------------------------------------------
// arrayToString StringNodeData
//------------------------------------------------------------------------------

template<>
std::string arrayToString<Node<StringNodeData>*>(std::vector<Node<StringNodeData>*> array);

//------------------------------------------------------------------------------
// arrayToString std::pair
//------------------------------------------------------------------------------

template<typename T1, typename T2>
std::string arrayToString(std::vector<std::pair<T1, T2>> mappings);

} // namespace capted
