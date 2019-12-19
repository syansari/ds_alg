//
// Created by Samir Ansari on 12/1/19.
//

#include <memory>
#include <iostream>
#include "../../lib/incl/linked_list.hpp"

// time complexity is O(n) and space complexity is O(1)


int find_ith_element(const LinkedList<int> &ll, int i) {


    int k = 0;
    std::shared_ptr<Node<int>> front = ll.getHead();
    std::shared_ptr<Node<int>> rear = front;

    while (front->next_node_ != nullptr && k < i) {

        front = front->next_node_;
        k++;
    }

    while (front != nullptr && rear != nullptr) {

        front = front->next_node_;
        rear = rear->next_node_;
    }

    return nullptr != rear ? rear->data_ : -1;
}


int main() {

    LinkedList<int> linkedList;

    linkedList.addNode(std::make_shared<Node<int>>(5));
    linkedList.addNode(std::make_shared<Node<int>>(6));
    linkedList.addNode(std::make_shared<Node<int>>(7));
    linkedList.addNode(std::make_shared<Node<int>>(8));
    linkedList.addNode(std::make_shared<Node<int>>(9));
    linkedList.addNode(std::make_shared<Node<int>>(10));
    linkedList.addNode(std::make_shared<Node<int>>(11));

    linkedList.display();

    std::cout << "Requested number is: " << find_ith_element(linkedList, 2) << '\n';
}