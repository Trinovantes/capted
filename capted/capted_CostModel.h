#pragma once

#include "capted_Node.h"

namespace capted {

//------------------------------------------------------------------------------
// Cost Model
//------------------------------------------------------------------------------

template<class NodeData>
class CostModel {
public:
    virtual float deleteCost(Node<NodeData>* n) = 0;
    virtual float insertCost(Node<NodeData>* n) = 0;
    virtual float renameCost(Node<NodeData>* n1, Node<NodeData>* n2) = 0;
};

} // namespace capted
