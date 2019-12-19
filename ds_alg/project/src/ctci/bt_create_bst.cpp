#include <iostream>
#include <vector>
#include <memory>

// create binary search tree using a sorted array

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
    std::shared_ptr<Node> head_ptr_;

public:
    void add_node(std::shared_ptr<Node>&, std::shared_ptr<Node>&);    
    int get_tree_height(std::shared_ptr<Node>);
    std::shared_ptr<Node>& getHead() {return head_ptr_; }
    void set_head(std::shared_ptr<Node> &head_ptr) { head_ptr_ = head_ptr; }
};

void BST::add_node(std::shared_ptr<Node> &head_ptr, std::shared_ptr<Node> &node_ptr )
{

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

        add_node(head_ptr->left_node_, node_ptr);
        return;
    }

    if ( head_ptr->value_ < node_ptr->value_ && head_ptr->right_node_ != nullptr) {

        add_node(head_ptr->right_node_, node_ptr);
        return;
    }
}

int BST::get_tree_height(std::shared_ptr<Node> head_ptr) {

    if (head_ptr == nullptr) {
        return 0;
    }

    return std::max(get_tree_height(head_ptr->right_node_), get_tree_height(head_ptr->left_node_)) + 1;
}


void create_tree(BST& bst, std::vector<int>& arr, const int begin, const int end) {

    if (arr.size() == 0) {
       return;
    }

    if (begin > end) {
        return;
    }

    if (begin == end) {

        //std::cout << "begin = " << "end = " << begin << '\n';

        std::shared_ptr<Node> node_ptr = std::make_shared<Node>(arr[begin]);
        bst.add_node(bst.getHead(), node_ptr);
        return;
    }

    int mid = (begin + end) / 2;
    std::shared_ptr<Node> node_ptr = std::make_shared<Node>(arr[mid]);
    bst.add_node(bst.getHead(), node_ptr);

    create_tree(bst, arr, 0, mid-1);
    create_tree(bst, arr, mid+1, end);

    return;
}

int main() {

    std::vector<int> arr = {1, 2, 3, 4, 5, 6 ,7, 8, 9};

    BST bst;
    create_tree(bst, arr, 0, arr.size()-1);

    std::cout << "tree height: " << bst.get_tree_height(bst.getHead()) << '\n';

}