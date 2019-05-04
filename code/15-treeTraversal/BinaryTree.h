#pragma once

template <typename T>
class BinaryTree {
  public:
    BinaryTree();
    void insert(T & t);
    T & remove();

  private:
    struct TreeNode {
        T & data;
        TreeNode *left, *right;
        TreeNode(T & t) : data(t) { };
    };

    TreeNode *root_;
};

#include "BinaryTree.hpp"
