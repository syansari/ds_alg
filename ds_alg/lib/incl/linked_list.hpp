//
// Created by Samir Ansari on 10/25/19.
//

#ifndef DS_ALG_LINKED_LIST_HPP
#define DS_ALG_LINKED_LIST_HPP

template<typename T>
class Node {

public:
    T data_;
    Node(const T data) : data_(data) {next_node_ = nullptr; };
    std::shared_ptr<Node<T>> next_node_;
};


template<typename T> 
class LinkedList {

private:
    std::shared_ptr<Node<T>> head_;
    int length_;

public:
    LinkedList() { head_ = nullptr; length_ = 0; }
    void addNode(std::shared_ptr<Node<T>> node);
    void deleteNode(int value);
    void display() const;
    std::shared_ptr<Node<T>> getHead() const;
    void setHead(std::shared_ptr<Node<T>> ptr);
};


#endif //DS_ALG_LINKED_LIST_HPP
