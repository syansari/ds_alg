// print the nodes of the binary tree level wise.

#include <memory>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>

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
    using level_map = std::unordered_map<int, std::deque<int>>;
    std::shared_ptr<Node> root_ = nullptr; 
    void create_binary_tree(std::vector<int> &);
    std::shared_ptr<Node> create_binary_tree(const std::vector<int>&, const int, const int);  
    void traversal() const;
    void print_level_wise() const;
    void build_level_map(level_map&, const std::shared_ptr<Node>&, int) const;
    int tree_height(const std::shared_ptr<Node> &) const;
};

int BinaryTree::tree_height(const std::shared_ptr<Node>& root) const {

    // base condition
    if (root == nullptr) {
        return 0;
    }

    return std::max(tree_height(root->left_node_), tree_height(root->right_node_)) + 1;
}

void BinaryTree::build_level_map(level_map& level, const std::shared_ptr<Node>& root, int current_level) const {

    // base condition
    if (root == nullptr) {
        return;
    }

    current_level++;

    if (level.find(current_level) == level.end()) {

        level.emplace(current_level, std::deque<int> (1, root->value_));
    }
    else {

    level.at(current_level).emplace_back(root->value_);
    }

    build_level_map(level, root->left_node_, current_level);
    build_level_map(level, root->right_node_, current_level);
}

void BinaryTree::print_level_wise() const {

    if (root_ == nullptr) {

        std::cout << "binary tree is empty" << '\n';
    }

    level_map level; 

    build_level_map(level, root_, 0);

    int h = tree_height(root_);

    std::cout << "height of the tree: " << h << '\n';

    for (int i =1; i <= h; i++ ) {

        std::deque<int> q = level.at(i);

        while (!q.empty()) {

            std::cout << q.front() << " ";
            q.pop_front();
        }

        std::cout << '\n';
    }

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

    std::vector<int> vv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    BinaryTree bt;
    bt.create_binary_tree(vv);     
    bt.print_level_wise();
}

