//
// Created by Samir Ansari on 10/26/19.
//

#ifndef DS_ALG_BINARY_TREE_HPP
#define DS_ALG_BINARY_TREE_HPP

#include <memory>

struct Node {

    int data_;
    std::shared_ptr<Node> left_, right_;
};


class BinaryTree {

private:
    std::shared_ptr<Node> root_;


public:
    BinaryTree();
    void insert(std::shared_ptr<Node> root, std::shared_ptr<Node> node);
 //   const std::shared_ptr<Node> search(int data) const;
    void in_order_traversal(const std::shared_ptr<Node>& node, std::ostream &sout) const;
    void pre_order_traversal(const std::shared_ptr<Node>& node, std::ostream &sout) const;
    void post_order_traversal(const std::shared_ptr<Node>& node, std::ostream &sout) const;
    std::shared_ptr<Node> create_node(int value) const;
    std::shared_ptr<Node> get_root() const;
    void set_root(std::shared_ptr<Node> ptr);
    int count_non_leaves(const std::shared_ptr<Node>& node);
    int count_leaves(const std::shared_ptr<Node> &node);
    int calculate_tree_height(const std::shared_ptr<Node> &node);
    void level_order_print(const std::shared_ptr<Node> &node);

};

#endif //DS_ALG_BINARY_TREE_HPP