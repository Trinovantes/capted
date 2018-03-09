#pragma once

#include <vector>
#include <functional>

namespace capted {

//------------------------------------------------------------------------------
// Node
//------------------------------------------------------------------------------

template<class NodeData>
class Node {
private:
    NodeData* nodeData;
    Node<NodeData>* parent;

    std::vector<Node<NodeData>*> children;
    std::vector<Node<NodeData>*> siblingPre;
    std::vector<Node<NodeData>*> siblingPost;

public:
    Node(NodeData* nodeData) {
        setNodeData(nodeData);
        parent = nullptr;
    }

    ~Node() {
        delete nodeData;

        for (Node<NodeData>* c : children) {
            delete c;
        }
    }

    int getNodeCount() const {
        int sum = 1;

        for (Node<NodeData>* c : children) {
            sum += c->getNodeCount();
        }

        return sum;
    }

    std::vector<Node<NodeData>*> &getChildren() {
        return children;
    }

    std::vector<Node<NodeData>*> getChildren() const {
        return children;
    }

    void addChild(Node<NodeData>* child) {
        assert(child);
        assert(!child->parent);
        child->parent = this;

        children.insert(children.end(), child->siblingPre.begin(), child->siblingPre.end());
        children.push_back(child);
        children.insert(children.end(), child->siblingPost.begin(), child->siblingPost.end());
    }

    void addSiblingPre(Node<NodeData>* sibiling) {
        assert(!parent);
        siblingPre.push_back(sibiling);
    }

    void addSiblingPost(Node<NodeData>* sibiling) {
        assert(!parent);
        siblingPost.push_back(sibiling);
    }

    NodeData* getNodeData() const {
        return nodeData;
    }

    void setNodeData(NodeData* nodeData)  {
        this->nodeData = nodeData;
    }

    void dfs(int depth, std::function<void(NodeData* currentNode, int depth)> callback) {
        callback(getNodeData(), depth);

        for (auto &child : getChildren()) {
            child->dfs(depth + 1, callback);
        }
    }
};

} // namespace capted
