//
// Created by Samir Ansari on 10/29/19.
//

#include <iostream>
#include <utility>
#include <fstream>
#include "../incl/bst_serde.hpp"


BstSerde::BstSerde(std::string filename, std::shared_ptr<BinaryTree> bst_ptr) :
filename_(std::move(filename)), bst_ptr_(std::move(bst_ptr)) {std::cout << " constructor called " << std::endl; }


void BstSerde::serializer() {

    std::ofstream f_out(filename_.c_str());
    bst_ptr_->in_order_traversal(bst_ptr_->get_root(), f_out);
}


std::shared_ptr<BinaryTree> BstSerde::deserializer() {

    int data = 0;
    std::ifstream f_in(filename_.c_str());

    if (!f_in.is_open()) {

        std::cout << "unable to open the file " << std::endl;
    }

    char c;
    while(f_in.get(c)) {
        std::cout << c << " ";
    }
}