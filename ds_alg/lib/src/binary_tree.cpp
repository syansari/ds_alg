//
// Created by Samir Ansari on 10/26/19.
//

#include <iostream>
#include <deque>
#include <utility>
#include "../incl/binary_tree.hpp"


BinaryTree::BinaryTree()  {

    root_ = nullptr;
};

std::shared_ptr<Node> BinaryTree::get_root() const { return root_; }

void BinaryTree::set_root(std::shared_ptr<Node> node) { root_ = std::move(node);}


int BinaryTree::count_non_leaves(const std::shared_ptr<Node>& node) {

    if (node == nullptr) {

        return 0;
    }

    if (node->left_ != nullptr || node->right_ != nullptr) {

        return count_non_leaves(node->left_) + count_non_leaves(node->right_) + 1;
    }

    return 0;
}

int BinaryTree::count_leaves(const std::shared_ptr<Node> &node) {

    if (node == nullptr) {

        return 0;
    }


    if (node->left_ == nullptr && node->right_ == nullptr) {

        return 1;
    }

    return count_leaves(node->right_) + count_leaves(node->left_);

}



int BinaryTree::calculate_tree_height(const std::shared_ptr<Node> &node) {

    if (node == nullptr) {
        return 0;
    }

    //return std::max(calculate_tree_height(node->left_), calculate_tree_height(node->right_));

    int left = calculate_tree_height(node->left_);
    int right = calculate_tree_height(node->right_);

    int value = left > right ? left : right;

    return value + 1;
}


void BinaryTree::in_order_traversal(const std::shared_ptr<Node>& node, std::ostream& sout) const {

    if (node == nullptr) {
        sout << "#" << " ";
        return;
    }

    in_order_traversal(node->left_, sout);
    sout << node->data_ << " ";
    in_order_traversal(node->right_, sout);
}

void BinaryTree::pre_order_traversal(const std::shared_ptr<Node>& node, std::ostream& sout) const {

    if (node == nullptr) {
        sout << "#" << " ";
        return;
    }

    sout << node->data_ << " ";
    pre_order_traversal(node->left_, sout);
    pre_order_traversal(node->right_, sout);
}

void BinaryTree::post_order_traversal(const std::shared_ptr<Node>& node, std::ostream& sout) const {

    if (node == nullptr) {
        sout << "#" << " ";
        return;
    }

    post_order_traversal(node->left_, sout);
    post_order_traversal(node->right_, sout);
    sout << node->data_ << " ";
}

void BinaryTree::insert(std::shared_ptr<Node> root, std::shared_ptr<Node> node) {

    if (root == nullptr) {

        root_ = node;
    }
    else if (root->data_ > node->data_ && root->left_ != nullptr) {

        insert(root->left_, node);
    }
    else if (root->data_ < node->data_ && root->right_ != nullptr) {

        insert(root->right_, node);
    }
    else if (root->data_ > node->data_ && root->left_ == nullptr) {

        root->left_ = node;
    }
    else if (root->data_ < node->data_ && root->right_ == nullptr) {

        root ->right_ = node;
    }
}

std::shared_ptr<Node> BinaryTree::create_node(int value) const {

    std::shared_ptr<Node> node = std::make_shared<Node>(Node());
    node->data_ = value;
    node->right_ = nullptr;
    node->left_ = nullptr;

    return node;
}

void BinaryTree::level_order_print(const std::shared_ptr<Node> &node) {

    std::deque<std::shared_ptr<Node>> q;

    q.push_back(node);

    while(!q.empty()) {

        int count = q.size();

        while(count > 0) {

            std::shared_ptr<Node> ptr = q.front();
            q.pop_front();

            std::cout << ptr->data_ << " ";

            q.emplace_back(ptr->left_);
            q.emplace_back(ptr->right_);

            count--;
        }
        std::cout << std::endl;
    }
}