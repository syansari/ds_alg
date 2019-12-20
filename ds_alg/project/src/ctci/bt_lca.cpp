#include <memory>
#include <vector>
#include <iostream>

// Step 1: build a binary tree (not BST) using the vector of characters passed to it. 
// Step 2: traverse through the binary tree.
// Step 3: find the lowest common ancestor of two given nodes 

class Node {

public:
    char value_;
    std::shared_ptr<Node> left_node_ = nullptr; 
    std::shared_ptr<Node> right_node_ = nullptr;
public:
    explicit Node(const int value);    
};

Node::Node(const int value) : value_(value) {};

class BinaryTree {

public:
    std::shared_ptr<Node> head_ = nullptr; 
    void create_binary_tree(std::vector<char> &);
    std::shared_ptr<Node> create_binary_tree(const std::vector<char>&, const int begin, const int end);  
    void traversal() const;
    void pre_order_traversal(const std::shared_ptr<Node>&) const;
    void in_order_traversal(const std::shared_ptr<Node>&) const;
    std::shared_ptr<Node> find_lca(const char, const char);
    std::shared_ptr<Node> find_lca(std::shared_ptr<Node>&, const char, const char);
};

std::shared_ptr<Node> BinaryTree::find_lca(const char m, const char n) {


    if (head_ == nullptr) {

        std::cout << " binary tree is empty" << '\n';
        return nullptr;
    }

    return find_lca(head_, m, n);
}

std::shared_ptr<Node> BinaryTree::find_lca(std::shared_ptr<Node>& head, const char m, const char n) {

    if (head == nullptr) {
        return nullptr;
    }

    if (head->value_ == m || head->value_ == n){
        return head;
    }
    
    std::shared_ptr<Node> left_tree = find_lca(head->left_node_, m, n);
    std::shared_ptr<Node> right_tree = find_lca(head->right_node_, m, n);

    if (left_tree && right_tree) {

        std::cout << left_tree->value_ << " <->  " << right_tree->value_ << '\n';
        return head;
    }

    return left_tree ? left_tree : right_tree;    
}

void BinaryTree::in_order_traversal(const std::shared_ptr<Node>& head) const {

    if (head == nullptr) {
        return;
    }   

    in_order_traversal(head->right_node_);
    std::cout << head->value_ << ' ';
    in_order_traversal(head->left_node_);
}



void BinaryTree::pre_order_traversal(const std::shared_ptr<Node>& head) const {

    if (head == nullptr) {
        return;
    }   

    std::cout << head->value_ << ' ';
    pre_order_traversal(head->right_node_);
    pre_order_traversal(head->left_node_);
}

void BinaryTree::traversal() const {

    if (head_ == nullptr) {

        std::cout << "binary tree is empty" <<  '\n';
        return;
    }

    std::cout << "pre order traversal: ";
    pre_order_traversal(head_);
    std::cout << '\n';
    std::cout << "in order traversal:  ";
    in_order_traversal(head_);
    std::cout << '\n';
}

std::shared_ptr<Node> BinaryTree::create_binary_tree(const std::vector<char>& vv, const int begin, const int end) {

    if (begin > end) {
        return nullptr;
    }

    int mid = (begin + end) / 2;

    std::shared_ptr<Node> node_ptr = std::make_shared<Node>(vv[mid]);

    node_ptr->left_node_ = create_binary_tree(vv ,begin , mid-1);
    node_ptr->right_node_ = create_binary_tree(vv, mid+1, end);

    return node_ptr;
}


void BinaryTree::create_binary_tree(std::vector<char> &vv) {

    head_ = create_binary_tree(vv, 0, vv.size()-1);
}

int main() {

    std::vector<char> vv = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};

    BinaryTree bt;

    bt.create_binary_tree(vv);
    bt.traversal();

    std::shared_ptr<Node> lca = bt.find_lca('l', 'b');

   if (lca == nullptr) {

        std::cout << "unable to find lca" << '\n';
        return 0;
    }

    std::cout << "lca of l and b is:  " << lca->value_ << '\n';
}












