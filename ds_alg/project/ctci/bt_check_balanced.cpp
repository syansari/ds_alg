#include <memory>
#include <iostream>
#include <vector>

class Node {

public:
    int value_;
    std::shared_ptr<Node> left_node_;
    std::shared_ptr<Node> right_node_;

    Node(int);
};

Node::Node(int value) : value_(value) {

    left_node_= nullptr;
    right_node_ = nullptr;
}

class BinaryTree {

private:
    void add_node(std::shared_ptr<Node> &, std::shared_ptr<Node> &);

public:
    std::shared_ptr<Node> head_ptr_;
    
    void add_node(std::shared_ptr<Node> &);
    bool isBalanced();
    int tree_height(std::shared_ptr<Node>&);
};

void BinaryTree::add_node(std::shared_ptr<Node>& node_ptr, std::shared_ptr<Node>& head_ptr) {

    if (node_ptr == nullptr) {
        return;
    }

    if (head_ptr_ == nullptr) {

        head_ptr_ = node_ptr;
        return;
    }

    if ( head_ptr->value_ > node_ptr->value_ && head_ptr->left_node_ == nullptr) {

        std::cout << "left_node null: " << node_ptr->value_  <<'\n';
        head_ptr->left_node_ = node_ptr;
        return;
    }
    
    if ( head_ptr->value_ < node_ptr->value_ && head_ptr->right_node_ == nullptr) {

        std::cout << "right_node null: " << node_ptr->value_ << '\n';
        head_ptr->right_node_ = node_ptr;
        return;
    }

    if ( head_ptr->value_ > node_ptr->value_ && head_ptr->left_node_ != nullptr) {

        add_node(node_ptr, head_ptr->left_node_);
        return;
    }

    if ( head_ptr->value_ < node_ptr->value_ && head_ptr->right_node_ != nullptr) {

        add_node(node_ptr, head_ptr->right_node_);
        return;
    }
}

void BinaryTree::add_node(std::shared_ptr<Node>& node_ptr) {

    add_node(node_ptr, head_ptr_);
}

int BinaryTree::tree_height(std::shared_ptr<Node> &head_ptr) {

    if (head_ptr == nullptr) {
        return 0;
    }
    return tree_height(head_ptr->left_node_) + tree_height(head_ptr->right_node_)+1;
}


bool BinaryTree::isBalanced() {

    if (head_ptr_ == nullptr) {

        return false;
    }

    return abs(tree_height(head_ptr_->left_node_) - tree_height(head_ptr_->right_node_)) <= 1; 
}

int main() {


    // false - std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // false - std::vector<int> arr = {1,3, 5, 7, 9, 2, 4, 6, 8, 10};
    std::vector<int> arr = {5, 2, 8, 1, 10, 4, 6, 7, 9, 3};

    BinaryTree bt;

    for (int i: arr) {

        std::shared_ptr<Node> node_ptr = std::make_shared<Node>(i);
        bt.add_node(node_ptr);
    }

    std::cout << "Is balanced: " << (bt.isBalanced() ? "True": "False") << '\n';
}


