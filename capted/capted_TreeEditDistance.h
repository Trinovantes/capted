#pragma once

#include "capted_CostModel.h"

namespace capted {

//------------------------------------------------------------------------------
// Distance Algorithm
//------------------------------------------------------------------------------

template<class NodeData>
class TreeEditDistance {
protected:
    const CostModel<NodeData>* costModel;

public:
    TreeEditDistance(CostModel<NodeData>* costModel) {
        this->costModel = costModel;
    }

    virtual float computeEditDistance(Node<NodeData>* t1, Node<NodeData>* t2) = 0;
};

} // namespace capted
