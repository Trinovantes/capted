#pragma once

#include <vector>

namespace capted {

//------------------------------------------------------------------------------
// Node
//------------------------------------------------------------------------------

template<class NodeData>
class Node {
private:
    NodeData* nodeData;
    std::vector<Node<NodeData>*> children;

public:
    Node(NodeData* nodeData) {
        setNodeData(nodeData);
    }

    ~Node() {
        delete nodeData;

        for (Node<NodeData>* c : children) {
            delete c;
        }
    }

    int getNodeCount() const  {
        int sum = 1;

        for (Node<NodeData>* c : children) {
            sum += c->getNodeCount();
        }

        return sum;
    }

    std::vector<Node<NodeData>*> getChildren() const  {
        return children;
    }

    void addChild(Node<NodeData>* child) {
        children.push_back(child);
    }

    NodeData* getNodeData() const {
        return nodeData;
    }

    void setNodeData(NodeData* nodeData)  {
        this->nodeData = nodeData;
    }
};

} // namespace capted
