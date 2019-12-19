//
// Created by Samir Ansari on 12/1/19.
//


#include <iostream>
#include <unordered_set>

class Node {

public:
    int data_;
    std::shared_ptr<Node> next_node_;
    explicit Node(int data);
};

Node::Node(int data) : data_(data) {};


class LinkedList {

public:
    std::shared_ptr<Node> head_;
    void add_node(std::shared_ptr<Node> np);
    std::shared_ptr<Node> delete_node(std::shared_ptr<Node> node);
    void delete_dupe();
    void traverse_ll();
    explicit LinkedList(std::shared_ptr<Node>& head);
};

LinkedList::LinkedList(std::shared_ptr<Node>& head) : head_(head) {};

void LinkedList::add_node(std::shared_ptr<Node> np) {

    np->next_node_ = head_;
    head_ = np;
}

void LinkedList::traverse_ll() {

    std::shared_ptr<Node> np = head_;
    while(np != nullptr) {

        std::cout << np->data_ << " ";
        np = np->next_node_;
    }
    std::cout << '\n';
}

void LinkedList::delete_dupe() {

    std::unordered_set<int> ss;

    std::shared_ptr<Node> np = head_;

    while(np != nullptr) {

        if (ss.find(np->data_) == ss.end()) {

            ss.insert(np->data_);
            np = np->next_node_;
            continue;
        }

        np = delete_node(np);
    }
}




std::shared_ptr<Node> LinkedList::delete_node(std::shared_ptr<Node> node) {

    std::shared_ptr<Node> np = head_;
    std::shared_ptr<Node> prev = nullptr;

    if (node == head_) {

        node->next_node_ = head_->next_node_;
        head_ = node;
        return head_->next_node_;
    }

    while(np != node) {

        prev = np;
        np = np->next_node_;
    }

    prev->next_node_ = np->next_node_;
    np = nullptr;
    return prev->next_node_;
}



int main() {

    auto np = std::make_shared<Node>(5);

    LinkedList linkedList(np);

    linkedList.add_node(std::make_unique<Node>(10));
    linkedList.add_node(std::make_unique<Node>(10));
    linkedList.add_node(std::make_unique<Node>(5));
    linkedList.add_node(std::make_unique<Node>(9));
    linkedList.add_node(std::make_unique<Node>(9));

    linkedList.traverse_ll();
    linkedList.delete_dupe();
    linkedList.traverse_ll();


}
