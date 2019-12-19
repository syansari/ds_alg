#include <iostream>

class Node
{

public:
    int data_;
    std::shared_ptr<Node> next_ptr_;
    Node(int data) : data_(data), next_ptr_(nullptr){};
    ~Node() { std::cout << "Node destructor called " << '\n'; }
};

class LinkedList
{

public:
    std::shared_ptr<Node> head_ = nullptr;
    void addNode(std::shared_ptr<Node> &node);
    void traverse();
};

void LinkedList::traverse()
{

    if (head_ == nullptr)
    {
        std::cout << "the list is empty" << '\n';
        return;
    }

    std::shared_ptr<Node> ptr = head_;

    while (ptr != nullptr)
    {
        std::cout << ptr->data_ << ' ';
        ptr = ptr->next_ptr_;
    }

    std::cout << '\n';
}

void LinkedList::addNode(std::shared_ptr<Node> &node)
{

    if (head_ == nullptr)
    {
        head_ = node;
        return;
    }

    node->next_ptr_ = head_;
    head_ = node;
}

bool isLoop(LinkedList &linkedList) {
   
      //TODO logic for loop detection

    return false;
}

int main() {


//TODO - build linked list and call method for loop detection. 
    


}