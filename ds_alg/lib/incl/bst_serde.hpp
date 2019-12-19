//
// Created by Samir Ansari on 10/29/19.
//

#ifndef DS_ALG_BST_SERDE_HPP
#define DS_ALG_BST_SERDE_HPP


#include "binary_tree.hpp"

class BstSerde {

private:
    std::shared_ptr<BinaryTree> bst_ptr_;
    std::string filename_;

public:

    BstSerde(std::string  filename, std::shared_ptr<BinaryTree> bst_ptr);
    void serializer();
    std::shared_ptr<BinaryTree>  deserializer();
    BstSerde() = delete;
};

#endif //DS_ALG_BST_SERDE_HPP
