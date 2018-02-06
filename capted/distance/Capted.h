#pragma once

#include "TreeEditDistance.h"

namespace capted {

//------------------------------------------------------------------------------
// Distance Algorithm (optimized)
//------------------------------------------------------------------------------

template<class NodeData>
class Capted : public TreeEditDistance<NodeData> {
public:
    Capted(CostModel<NodeData>* costModel) : TreeEditDistance<NodeData>(costModel) {

    }

    virtual float computeEditDistance(Node<NodeData>* t1, Node<NodeData>* t2) override {
        return 0xDEADBEEF;
    }
};

} // namespace capted
