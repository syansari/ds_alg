//
// Created by Samir Ansari on 10/25/19.
// Create linked list, add node to the LL, delete node from the linked list.

#include <iostream>
#include <memory>
#include "../incl/linked_list.hpp"

using namespace std;

template <typename T>
void LinkedList<T>::addNode(shared_ptr<Node<T>> node) {

    if (head_ == nullptr) {

        head_ = node;
    } else {

        shared_ptr<Node<T>> temp = head_;
        head_ = node;
        head_->next_node_ = temp;
        length_++;
    }
}

template <typename T>
void LinkedList<T>::deleteNode(int value) {

    shared_ptr<Node<T>> temp = head_;
    shared_ptr<Node<T>> prev = nullptr;

    while(temp != nullptr && temp->data_ != value) {

        prev = temp;
        temp = temp->next_node_;
    }

    if (temp == nullptr) {

        cout << "unable to find the item" << endl;
    }
    else {

        temp = temp->next_node_;
        prev->next_node_ = temp;
    }

    cout << "linked list after node deletion: ";
    display();
}


template <typename T>
void LinkedList<T>::display() const {

    shared_ptr<Node<T>> temp = head_;

    while(temp != nullptr) {

        cout << temp->data_ << " ";
        temp = temp->next_node_;
    }

    cout << endl;
}

template <typename T>
shared_ptr<Node<T>> LinkedList<T>::getHead() const {

    return this->head_;
}

template <typename T>
void LinkedList<T>::setHead(std::shared_ptr<Node<T>> ptr) {

    this->head_  = ptr;
}

template class LinkedList<int>;
template class LinkedList<char>;




