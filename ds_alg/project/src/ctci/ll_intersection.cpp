#include <iostream>
#include <memory>

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
    int getLength();
    void traverse();
    ~LinkedList();
};

int LinkedList::getLength()
{
    int i = 0;

    std::shared_ptr<Node> t = head_;

    while (t != nullptr) {

        i++;
        t = t->next_ptr_;
    }

    return i;
}

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

LinkedList::~LinkedList() { std::cout << "linked list destructor called " << '\n'; }

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

bool isIntersecting(LinkedList &l1, LinkedList &l2)
{

    // get the length of both linked list
    int len2 = l2.getLength();
    int len1 = l1.getLength();

    std::shared_ptr<Node> p1 = l1.head_;
    std::shared_ptr<Node> p2 = l2.head_;

    // get the diff of length
    int diff = abs(len1 - len2);

    //bump the longer linked list by the amount of diff.

    if (len1 > len2)
    {

        while (diff > 0)
        {
            p1 = p1->next_ptr_;
            diff--;
        }
    }

    if (len2 > len1)
    {

        while (diff > 0)
        {
            p2 = p2->next_ptr_;
            diff--;
        }
    }

     // traverse through both linked list until the node reference are same. 
    std::cout << "len1 = " << len1 << " len2 = " << len2 << '\n';
    while(p1 != p2 || p1 != nullptr || p2 != nullptr) {

       p1 = p1->next_ptr_;
       p2 = p2->next_ptr_;
    }

    return p1 == p2;
}

int main()
{

    LinkedList ll1;
    LinkedList ll2;

    std::shared_ptr<Node> node01 = std::make_shared<Node>(3);
    std::shared_ptr<Node> node02 = std::make_shared<Node>(4);

    ll1.addNode(node02);
    ll1.addNode(node01);

    for (int i = 2; i >= 0; i--)
    {

        auto node = std::make_shared<Node>(i);
        ll1.addNode(node);
    }

    ll2.addNode(node02);
    ll2.addNode(node01);

    for (int i = 10; i >= 5; i--)
    {

        auto node = std::make_shared<Node>(i);
        ll2.addNode(node);
    }

    std::cout << "is intersecting: " << (isIntersecting(ll1, ll2) ? "true" : "false") << "\n";
}
