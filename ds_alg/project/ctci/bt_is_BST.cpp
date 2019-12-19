#include <iostream>
#include <memory>
#include <vector>

// is the given tree BST 

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
    bool isBST(std::shared_ptr<Node>&);

public:
    std::shared_ptr<Node> head_ptr_;
    void add_node(std::shared_ptr<Node> &);
    bool isBST();
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

        std::cout << "left_node: " << node_ptr->value_  <<'\n';
        head_ptr->left_node_ = node_ptr;
        return;
    }
    
    if ( head_ptr->value_ < node_ptr->value_ && head_ptr->right_node_ == nullptr) {

        std::cout << "right_node: " << node_ptr->value_ << '\n';
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

bool BinaryTree::isBST(std::shared_ptr<Node>& head_ptr) {

    if (head_ptr == nullptr) {
        return true;
    }

    isBST(head_ptr->left_node_) && isBST(head_ptr->right_node_);

    std::cout << "isBST value: " << head_ptr->value_ << '\n';

    if (head_ptr->left_node_ && head_ptr_->right_node_) {    

        return head_ptr->value_ > head_ptr->left_node_->value_ && head_ptr->value_ < head_ptr->right_node_->value_;
    }
    else if(head_ptr->left_node_) {

        return head_ptr->value_ > head_ptr->left_node_->value_;
    }
    else if(head_ptr->right_node_) {

        return head_ptr->value_ > head_ptr->right_node_->value_;
    }
    else {
        return true;
    }
}

bool BinaryTree::isBST() {

    return isBST(head_ptr_);
}

int main() {

    std::vector<int> arr = {5, 2, 8, 1, 10, 4, 6, 7, 9, 3};

    BinaryTree bt;

    for (int i: arr) {

        std::shared_ptr<Node> node_ptr = std::make_shared<Node>(i);
        bt.add_node(node_ptr);
    }

    std::cout << (bt.isBST() ? "true" : "false") << '\n'; 

}