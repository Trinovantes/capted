#pragma once

#include <vector>
#include <list>
#include <functional>

namespace capted {

//------------------------------------------------------------------------------
// Node
//------------------------------------------------------------------------------

template<class Data>
class Node {
private:
    Data* data;
    Node<Data>* parent;
    std::list<Node<Data>*> children;

public:
    Node(Data* data) : data(data), parent(nullptr) {
        // nop
    }

    virtual ~Node() {
        delete data;

        for (Node<Data>* c : children) {
            delete c;
        }
    }

    void giveChildrenToGrandparents(typename std::list<Node<Data>*>::iterator iter) {
        parent->children.insert(iter, children.begin(), children.end());

        for (Node<Data>* child : children) {
            child->parent = parent;
        }

        children.clear();
    }

    int getNodeCount() const {
        int sum = 1;

        for (Node<Data>* c : children) {
            sum += c->getNodeCount();
        }

        return sum;
    }

    std::list<Node<Data>*> &getChildren() {
        return children;
    }

    std::list<Node<Data>*> getChildren() const {
        return children;
    }

    std::vector<Node<Data>*> getChildrenAsVector() const {
        return std::vector<Node<Data>*>(children.begin(), children.end());
    }

    Node<Data>* getParent() {
        return parent;
    }

    void setParent(Node<Data>* parent) {
        assert(this->parent == nullptr);
        this->parent = parent;
    }

    void addChild(Node<Data>* child) {
        assert(child);
        assert(!child->parent);

        child->setParent(this);
        children.push_back(child);
    }

    Data* getData() const {
        return data;
    }

    void dfs(std::function<void(Node<Data>* currentNode, int depth)> callback, int depth = 0) {
        callback(this, depth);

        for (Node<Data>* child : children) {
            child->dfs(callback, depth + 1);
        }
    }
};

} // namespace capted
