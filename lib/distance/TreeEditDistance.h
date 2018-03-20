#pragma once

#include "CostModel.h"
#include "node/NodeIndexer.h"

namespace capted {

//------------------------------------------------------------------------------
// Distance Algorithm
//------------------------------------------------------------------------------

typedef std::pair<int, int> IntPair;

template<class NodeData>
class TreeEditDistance {
protected:
    NodeIndexer<NodeData>* it1;
    NodeIndexer<NodeData>* it2;
    int size1;
    int size2;
    const CostModel<NodeData>* costModel;

    void init(Node<NodeData>* t1, Node<NodeData>* t2) {
        it1 = new NodeIndexer<NodeData>(t1, costModel);
        it2 = new NodeIndexer<NodeData>(t2, costModel);
        size1 = it1->getSize();
        size2 = it2->getSize();
    }

public:
    TreeEditDistance(CostModel<NodeData>* costModel) : costModel(costModel) {
        it1 = nullptr;
        it2 = nullptr;
        size1 = -1;
        size2 = -1;
    }

    ~TreeEditDistance() {
        delete it1;
        delete it2;
    }

    virtual float computeEditDistance(Node<NodeData>* t1, Node<NodeData>* t2) = 0;
};

} // namespace capted
