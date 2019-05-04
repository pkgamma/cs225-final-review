/**
 * BinaryTree-backed Dictionary data structure.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

#include <iostream>
#include <sstream>

template <typename K, typename D>
class AVL {
  public:
    AVL();
    const D & find(const K & key);
    void insert(const K & key, const D & data);
    const D & remove(const K & key);


  private:
    class TreeNode {
      public:
        const K & key;
        const D & data;
        TreeNode *left, *right;
        int height;
        TreeNode(const K & key, const D & data) : key(key), data(data), left(nullptr), right(nullptr), height(0) { }

        // An overloaded operator<<, allowing us to print the stack via `cout<<`:
        friend std::ostream& operator<<(std::ostream & os, const TreeNode & cur) {
          //if (!&cur) { return os << &cur; }

          int l_balance = -1;
          if (cur.left) { l_balance = cur.left->height; }

          int r_balance = -1;
          if (cur.right) { r_balance = cur.right->height; }

          int b = r_balance - l_balance;

          os << "[" << cur.key << ", h=" << cur.height << ", b=" << b << "] -> {";
          if (cur.left) { os << *cur.left; }
          else          { os << cur.left; }
          os << ",";
          if (cur.right) { os << *cur.right; }
          else           { os << cur.right; }
          os << "}";

          return os;
        }
    };

    TreeNode *root_;

    TreeNode *& _find(const K & key, TreeNode *& cur) const;
    void _insert(const K & key, const D & data, TreeNode *& cur);
    const D & _remove(TreeNode *& cur);
    void _swap(TreeNode *& a, TreeNode *& b);

    int height(TreeNode *& cur);

    void _rotateRight(TreeNode *& cur);
    void _rotateLeft(TreeNode *& cur);
    void _rotateRightLeft(TreeNode *& cur);
    void _rotateLeftRight(TreeNode *& cur);

    void _ensureBalance(TreeNode *& cur);
    void _updateHeight(TreeNode *& cur);
    const D & _iopRemove(TreeNode *& node, TreeNode *& iop);

    const D & _findAndRemove(const K & key, TreeNode *& cur);
};

#include "AVL.hpp"
