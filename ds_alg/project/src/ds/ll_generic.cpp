//
// Created by Samir Ansari on 10/25/19.
//

#include <iostream>
#include <main.h>
#include <set>
#include <unordered_set>
#include <memory>
#include "../../lib/incl/linked_list.hpp"

using namespace std;


bool check_loop(shared_ptr<Node<int>> temp) {

    unordered_set<shared_ptr<Node<int>>> hash_set;

    do {

        if (hash_set.find(temp) != hash_set.end()) {
            return true;
        }

    } while((temp = temp->next_node_) != nullptr);

    return false;
}

void reverseLinkedList(shared_ptr<Node<int>> &head) {

    shared_ptr<Node<int>> current = head;
    shared_ptr<Node<int>> prev = nullptr;
    shared_ptr<Node<int>> next = nullptr;

    while(current != nullptr) {

        next = current->next_node_;
        current->next_node_ = prev;
        prev = current;
        current = next;
    }

    head = prev;

    std::cout << "linked list reversed: ";
}



int main(int argc, char* argv[]) {


     unique_ptr<LinkedList<int>> linkedList(new LinkedList<int>());

    for (auto i: {1, 2, 3, 4, 5, 6, 7, 8, 9}) {

        linkedList->addNode(make_shared<Node<int>>(Node<int>(i)));
    }

    cout << "current linked list: ";
    linkedList->display();
    std::shared_ptr<Node<int>> head_ptr = linkedList->getHead();


    int option;
    cout << "select option 1, 2, 3: ";
    cin >> option;

    switch(option) {

        case 1:
            linkedList->deleteNode(6);
            break;

        case 2:
            check_loop(head_ptr) ? cout << "loop detected" : cout << " no loop present";
            break;

        case 3:
            reverseLinkedList(head_ptr);
            linkedList->setHead(head_ptr);
            break;

        default:
            std::cout << "bad option selected";
            exit(-1);
    }

    linkedList->display();

    cout << endl <<"end of the program" << endl;
}