// check with T1 present in T2. The tree should be identical

#include <memory>
#include <iostream>
#include <vector>
#include <iomanip>

class Node {

public:
    int value_;
    std::shared_ptr<Node> left_node_;
    std::shared_ptr<Node> right_node_;

    explicit Node(int);
};

Node::Node(int value) : value_(value) {

    left_node_= nullptr;
    right_node_ = nullptr;
}

class BinaryTree {

public:
    std::shared_ptr<Node> root_ = nullptr; 
    void create_binary_tree(std::vector<int> &);
    std::shared_ptr<Node> create_binary_tree(const std::vector<int>&, const int, const int);  
};

void inorder_traversal(std::shared_ptr<Node>& root, std::vector<int>& inorder_list) {

    if (root == nullptr) {
        return;
    }

    inorder_traversal(root->left_node_, inorder_list);
    inorder_list.emplace_back(root->value_);
    inorder_traversal(root->right_node_, inorder_list);
}

void preorder_traversal(std::shared_ptr<Node>& root, std::vector<int>& preorder_list) {

    if (root == nullptr) {
        return;
    }

    preorder_list.emplace_back(root->value_);
    preorder_traversal(root->left_node_, preorder_list);
    preorder_traversal(root->right_node_, preorder_list);
}

std::shared_ptr<Node> is_root_present(std::shared_ptr<Node>& root1, std::shared_ptr<Node>& root2 ) {

    if (root1 == nullptr) {
        return nullptr;
    }

    std::cout << "b1 root: " << root1->value_ << " ";
    std::cout << "b2 root: " << root2->value_ << '\n';

    if (root1->value_ == root2->value_) {
        return root1;
    }

    std::shared_ptr<Node> left_ptr = is_root_present(root1->left_node_, root2);
    std::shared_ptr<Node> right_ptr = is_root_present(root1->right_node_, root2);

    if (left_ptr || right_ptr) {

        return left_ptr ? left_ptr : right_ptr;
    }

    return nullptr;
}

bool is_subtree(BinaryTree& b1, BinaryTree& b2) {

    std::shared_ptr<Node> sub_root1;

    if ((sub_root1 = is_root_present(b1.root_, b2.root_)) == nullptr) {

        return false;
    }

    std::vector<int> preorder_b1, preorder_b2, inorder_b1, inorder_b2;

    preorder_traversal(b2.root_, preorder_b2);
    inorder_traversal(b2.root_, inorder_b2);

    preorder_traversal(sub_root1, preorder_b1);
    inorder_traversal(sub_root1, inorder_b1);

    return preorder_b1 == preorder_b2 && inorder_b1 == inorder_b2;
}


std::shared_ptr<Node> BinaryTree::create_binary_tree(const std::vector<int>& vv, const int begin, const int end) {

    // base condition
    if (begin > end) {
        return nullptr;
    }

    int mid = (begin + end) / 2;

    std::shared_ptr<Node> node_ptr = std::make_shared<Node>(vv[mid]);

    node_ptr->left_node_ = create_binary_tree(vv ,begin , mid-1);
    node_ptr->right_node_ = create_binary_tree(vv, mid+1, end);

    return node_ptr;
}


void BinaryTree::create_binary_tree(std::vector<int> &vv) {

    root_ = create_binary_tree(vv, 0, vv.size()-1);
}


int main() {

    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> v2 = {8, 9, 10, 11, 12, 13};

    BinaryTree bt1, bt2;

    bt1.create_binary_tree(v1);
    bt2.create_binary_tree(v2);

    std::cout << "is subtree: " << std::boolalpha << is_subtree(bt1, bt2) << '\n';
}