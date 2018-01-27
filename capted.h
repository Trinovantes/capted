#pragma once

#include <string>
#include <vector>
#include <iostream>

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

//------------------------------------------------------------------------------
// Parser
//------------------------------------------------------------------------------

template<class NodeData>
class InputParser {
public:
    InputParser() { }
    virtual Node<NodeData>* getRoot() = 0;
};

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

    virtual float computeEditDistance(Node<NodeData> t1, Node<NodeData> t2) = 0;
};

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
