//
// Created by Samir Ansari on 12/3/19.
//

#include <memory>
#include <iostream>
#include "../../lib/incl/linked_list.hpp"


void delete_middle_node(LinkedList<int> &ll) {


    std::shared_ptr<Node<int>> fp = ll.getHead();
    std::shared_ptr<Node<int>> rp = fp;

    while (true) {

        if ((fp = fp->next_node_) == nullptr) {
            break;
        }

        if ((fp = fp->next_node_) == nullptr) {
            break;
        }

        if ((rp = rp->next_node_) == nullptr) {
            break;
        }
    }

    std::cout << "Node to delete: " << rp->data_;
}


int main() {

    LinkedList<int> linkedList;

    for (int i = 1; i <= 15; i++ ) {

        linkedList.addNode(std::make_shared<Node<int>>(i));
    }

    delete_middle_node(linkedList);
}