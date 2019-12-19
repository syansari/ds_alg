//
// Created by Samir Ansari on 12/8/19.
//

#include <memory>
#include "../../lib/incl/linked_list.hpp"
#include <stack>
#include <iostream>


bool isPalindrome(LinkedList<char> &ll) {

    std::shared_ptr<Node<char>> head = ll.getHead();

    std::stack<char> stack;

    std::shared_ptr<Node<char>> slow = head;
    std::shared_ptr<Node<char>> fast = head;

    // use the runner approach to get to the middle of the linked list
    while(slow != nullptr && fast != nullptr) {

        if (fast->next_node_ == nullptr) {
            break;
        }

        fast = fast->next_node_->next_node_;
        slow = slow->next_node_;
    }

    std::shared_ptr<Node<char>> temp = slow;

    while(temp != nullptr) {

        stack.emplace(temp->data_);
        temp = temp->next_node_;
    }

    // compare the stack contents with the first half of LL
    temp = head;
    while(temp != slow && !stack.empty()) {

        if (stack.top() != temp->data_) {

            return false;
        }

        stack.pop();
        temp = temp->next_node_;
    }

    return  temp == slow || stack.empty();
}

int main() {

    LinkedList<char> ll;

    ll.addNode(std::make_shared<Node<char>>('t'));
    ll.addNode(std::make_shared<Node<char>>('a'));
    ll.addNode(std::make_shared<Node<char>>('c'));
    ll.addNode(std::make_shared<Node<char>>('o'));
    ll.addNode(std::make_shared<Node<char>>('c'));
    ll.addNode(std::make_shared<Node<char>>('a'));
    ll.addNode(std::make_shared<Node<char>>('t'));

    std::cout << (isPalindrome(ll) ? "true" : "false") << '\n';
}

