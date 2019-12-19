//
// Created by Samir Ansari on 10/26/19.
//

#include <iostream>
#include <thread>
#include "../../lib/incl/binary_tree.hpp"
#include "../../lib/incl/bst_serde.hpp"

using namespace std;


void in_order_traversal(const shared_ptr<BinaryTree> &bt) {

    if (bt->get_root() == nullptr) {

        cout << "binary tree is empty" << endl;
    }

    bt->in_order_traversal(bt->get_root(), std::cout);
}

void pre_order_traversal(const shared_ptr<BinaryTree> &bt) {

    if (bt->get_root() == nullptr) {

        cout << "binary tree is empty" << endl;
    }

    bt->pre_order_traversal(bt->get_root(), std::cout);
}

void post_order_traversal(const shared_ptr<BinaryTree> &bt) {

    if (bt->get_root() == nullptr) {

        cout << "binary tree is empty" << endl;
    }

    bt->post_order_traversal(bt->get_root(), std::cout);
}

void bst_serde(const shared_ptr<BstSerde>& bst_ptr) {

    bst_ptr->serializer();
    cout << "BST serialized" << endl;

    this_thread::sleep_for(chrono::seconds(1));
    cout << endl << "BST deserialized" << endl;
    bst_ptr->deserializer();
}


void count_leaves_and_non_leaves(const shared_ptr<BinaryTree> &bt_ptr) {

    if (bt_ptr->get_root() == nullptr) {

        cout << "binary tree is empty" << endl;
    }

    std::cout << "non-leaves count: " << bt_ptr->count_non_leaves(bt_ptr->get_root()) << std::endl;
    std::cout << "leaves count: " << bt_ptr->count_leaves(bt_ptr->get_root()) << std::endl;
}

void build_binary_tree(std::shared_ptr<BinaryTree> &ptr) {

/*
    ptr->insert(ptr->get_root(), ptr->create_node(3));
    ptr->insert(ptr->get_root(), ptr->create_node(2));
    ptr->insert(ptr->get_root(), ptr->create_node(1));
    ptr->insert(ptr->get_root(), ptr->create_node(0));
    ptr->insert(ptr->get_root(), ptr->create_node(4));
    ptr->insert(ptr->get_root(), ptr->create_node(5));
    ptr->insert(ptr->get_root(), ptr->create_node(6));
    */

    ptr->set_root(ptr->create_node(3));
    ptr->get_root()->left_ = ptr->create_node(1);
    ptr->get_root()->left_->left_ = ptr->create_node(0);
    ptr->get_root()->left_->right_ = ptr->create_node(2);
    ptr->get_root()->right_ = ptr->create_node(5);
    ptr->get_root()->right_->left_ = ptr->create_node(4);
    ptr->get_root()->right_->right_ = ptr->create_node(6);

    std::cout << "binary tree built" << std::endl;
}

void calculate_tree_height(std::shared_ptr<BinaryTree> &ptr) {

    std::cout << "and the tree height is: " << ptr->calculate_tree_height(ptr->get_root()) << std::endl;
}

void level_order_print(std::shared_ptr<BinaryTree> &ptr) {

    ptr->level_order_print(ptr->get_root());
}


int main() {


    int choice = -1;
    int data = 0;
    shared_ptr<BinaryTree> binaryTree(new BinaryTree());
    shared_ptr<BstSerde> bstSerde(new BstSerde("/Users/ansari/junk/bst_serialized.txt", binaryTree));

    shared_ptr<Node> bt = nullptr;

    while (choice) {

        cout << "enter your choice, possible options are: "
                "1, 2, 3, 4, 5, 6. 0 is for exit program" << endl;

        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter the value for node: ";
                cin >> data;
                binaryTree->insert(binaryTree->get_root(), binaryTree->create_node(data));
                break;

            case 2:
                in_order_traversal(binaryTree);
                cout << endl;
                break;

            case 3:
                pre_order_traversal(binaryTree);
                break;

            case 4:
                bst_serde(bstSerde);
                break;

            case 5:
                build_binary_tree(binaryTree);
                break;
            case 6:
                count_leaves_and_non_leaves(binaryTree);
                break;
            case 7:
                calculate_tree_height(binaryTree);
                break;

            case 8:
                level_order_print(binaryTree);
                break;

            default:
                cout << " Invalid entry" << endl;
        }
    }

    cout << "End of program" << endl;
}