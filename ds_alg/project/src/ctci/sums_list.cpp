//
// Created by Samir Ansari on 12/8/19.
//
// Add two numbers represented by linked list. 

#include <memory>
#include "../../lib/incl/linked_list.hpp"
#include <iostream>

int build_integer(std::shared_ptr<LinkedList<int>> &ll) {

    int value = 0;
    int multiple = 1;

    std::shared_ptr<Node<int>> node_ptr = ll->getHead();

    if (node_ptr == nullptr) {

        return value;
    }

    std::shared_ptr<Node<int>> temp_ptr = node_ptr;

    while(temp_ptr->next_node_ != nullptr) {

        temp_ptr = temp_ptr->next_node_;
        multiple *= 10;
    }


    while(node_ptr != nullptr) {

        value += node_ptr->data_ * multiple;
        node_ptr = node_ptr->next_node_;
        multiple /= 10;
    }

    return value;
}




int build_integer_reverse(std::shared_ptr<LinkedList<int>> &ll) {

    int value = 0;
    int multiple = 1;

    std::shared_ptr<Node<int>> node_ptr = ll->getHead();

    if (node_ptr == nullptr) {

        return value;
    }

    while(node_ptr != nullptr) {

        value += node_ptr->data_ * multiple;
        node_ptr = node_ptr->next_node_;
        multiple *= 10;
    }

    return value;
}

int main() {

    std::shared_ptr<LinkedList<int>> linkedList01 = std::make_shared<LinkedList<int>>();
    std::shared_ptr<LinkedList<int>> linkedList02 = std::make_shared<LinkedList<int>>();

    linkedList01->addNode(std::make_shared<Node<int>>(1));
    linkedList01->addNode(std::make_shared<Node<int>>(2));
    linkedList01->addNode(std::make_shared<Node<int>>(3));

    linkedList02->addNode(std::make_shared<Node<int>>(4));
    linkedList02->addNode(std::make_shared<Node<int>>(5));
    linkedList02->addNode(std::make_shared<Node<int>>(6));

    std::cout << "sum reverse: " << build_integer_reverse(linkedList01) + build_integer_reverse(linkedList02) << '\n';
    std::cout << "sum : " << build_integer(linkedList01) + build_integer(linkedList02) << '\n';
}