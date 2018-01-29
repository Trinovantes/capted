#pragma once

#include "capted_Node.h"

namespace capted {

//------------------------------------------------------------------------------
// Parser
//------------------------------------------------------------------------------

template<class NodeData>
class InputParser {
public:
    InputParser() { }
    virtual Node<NodeData>* getRoot() = 0;
};

} // namespace capted
