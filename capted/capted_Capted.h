#pragma once

#include "capted_TreeEditDistance.h"

namespace capted {

//------------------------------------------------------------------------------
// Distance Algorithm (optimized)
//------------------------------------------------------------------------------

template<class NodeData>
class Capted : public TreeEditDistance<NodeData> {
    const CostModel<NodeData>* costModel;

public:
    Capted(CostModel<NodeData>* costModel) : TreeEditDistance<NodeData>(costModel) {

    }

    ~Capted() {

    }

    virtual float computeEditDistance(Node<NodeData> t1, Node<NodeData> t2) {

    }
};

} // namespace capted
