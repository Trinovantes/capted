#pragma once

#include "capted_TreeEditDistance.h"

namespace capted {

//------------------------------------------------------------------------------
// Distance Algorithm (simple)
//------------------------------------------------------------------------------

template<class NodeData>
class AllPossibleMappings : public TreeEditDistance<NodeData> {
public:
    AllPossibleMappings(CostModel<NodeData>* costModel) : TreeEditDistance<NodeData>(costModel) {

    }

    virtual float computeEditDistance(Node<NodeData> t1, Node<NodeData> t2) {

    }
};

} // namespace capted
