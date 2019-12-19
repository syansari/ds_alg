#include <iostream>
#include <vector>
#include <memory>
#include <array>
#include <iomanip>

// Get the in-order successor of a given node 

// Option 1 - do in-order traversal to achive it. Time complexity - O(n)
// Option 2 - check for left most node in the right tree of the given node. 
// This is the implementation of Option 2. 

class Node {

public:
    int value_;
    std::shared_ptr<Node> left_node_;
    std::shared_ptr<Node> right_node_;
    Node(const int);
};

Node::Node(const int value) : value_(value) {

    left_node_ = nullptr;
    right_node_ = nullptr;
}

class BST {

private:
    std::shared_ptr<Node> head_ptr_ = nullptr;
    void add_node(std::shared_ptr<Node>&, std::shared_ptr<Node>&);    


public:
    void add_node(std::shared_ptr<Node>&);
    int in_order_successor(std::shared_ptr<Node> &);

};

void BST::add_node(std::shared_ptr<Node> &head_ptr, std::shared_ptr<Node> &node_ptr)
{

    if (node_ptr == nullptr) {
        return;
    }

    if (head_ptr_ == nullptr) {

        head_ptr_ = node_ptr;
        return;
    }

    if ( head_ptr->value_ > node_ptr->value_ && head_ptr->left_node_ == nullptr) {

        head_ptr->left_node_ = node_ptr;
        return;
    }
    
    if ( head_ptr->value_ < node_ptr->value_ && head_ptr->right_node_ == nullptr) {

        head_ptr->right_node_ = node_ptr;
        return;
    }

    if ( head_ptr->value_ > node_ptr->value_ && head_ptr->left_node_ != nullptr) {

        add_node(head_ptr->left_node_, node_ptr);
        return;
    }

    if ( head_ptr->value_ < node_ptr->value_ && head_ptr->right_node_ != nullptr) {

        add_node(head_ptr->right_node_, node_ptr);
        return;
    }
}

void BST::add_node(std::shared_ptr<Node>& node_ptr) {

    add_node(head_ptr_, node_ptr);
}



int BST::in_order_successor(std::shared_ptr<Node> &node_ptr) {

    if(node_ptr->right_node_) {

        std::shared_ptr<Node> left_node = node_ptr->right_node_->left_node_;
        std::shared_ptr<Node> prev = nullptr;

        if (left_node == nullptr) {
            
            return node_ptr->right_node_->value_;
        }

        while(left_node) {

            prev = left_node;
            left_node = left_node->left_node_;
        }

        
        if (prev != nullptr) {
            return prev->value_;
        }

    }

    std::shared_ptr<Node> current_ptr = head_ptr_;
    while (current_ptr != nullptr) {

        if (current_ptr->value_ > node_ptr->value_) {
            break;
        }

        current_ptr = current_ptr->right_node_;
    }

    return current_ptr->value_;
}


int main() {

    BST bst;
    std::array<int, 10> arr {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    std::shared_ptr<Node> temp;

    for (int x: arr) {
        
        std::shared_ptr<Node> node_ptr = std::make_shared<Node>(x);
        bst.add_node(node_ptr); 
        if (x == 4) {
            temp = node_ptr;
        }
    }

    std::cout << "in-order successor of 4: " << bst.in_order_successor(temp) << '\n';
}