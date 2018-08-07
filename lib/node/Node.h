#pragma once

#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <cassert>

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

    Node<Data>* clone() {
        auto copy = new Node<Data>(cloneData(data));

        for (Node<Data>* child : children) {
            copy->addChild(child->clone());
        }

        return copy;
    }

    void insertChild(typename std::list<Node<Data>*>::iterator destIter, Node<Data>* child) {
        assert(child);
        children.insert(destIter, child);
        child->setParent(this);
    }

    void removeChild(Node<Data>* child, bool keepGrandChildren = true) {
        bool madeChange = false;

        auto iter = children.begin();
        while (iter != children.end()) {
            if (*iter == child) {
                assert(!madeChange);
                iter = children.erase(iter);
                madeChange = true;
            } else {
                iter++;
            }
        }

        if (keepGrandChildren) {
            child->children.clear();
        }

        assert(madeChange);
        delete child;
    }

    void replaceChild(Node<Data>* child, Node<Data>* replacement) {
        bool madeChange = false;

        auto iter = children.begin();
        while (iter != children.end()) {
            if (*iter == child) {
                assert(!madeChange);
                *iter = replacement;
                madeChange = true;
            }

            iter++;
        }

        assert(madeChange);
        delete child;
    }

    void abandonFirstChild() {
        Node<Data>* front = children.front();
        children.pop_front();
        delete front;
    }

    typename std::list<Node<Data>*>::iterator getMyIter() const {
        return std::find(parent->getChildren().begin(), parent->getChildren().end(), this);
    }

    void giveChildrenToGrandparents(typename std::list<Node<Data>*>::iterator destIter) {
        parent->children.insert(destIter, children.begin(), children.end());

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

    Node<Data>* getIthChild(int i) const {
        assert(i >= 0);
        assert(i < (int)children.size());

        auto it = children.begin();
        while (i > 0) {
            it++;
            i--;
        }

        return *it;
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
