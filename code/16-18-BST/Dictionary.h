/**
 * BinaryTree-backed Dictionary data structure.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

template <typename K, typename D>
class Dictionary {
  public:
    Dictionary();
    const D & find(const K & key);
    void insert(const K & key, const D & data);
    const D & remove(const K & key);

  private:
    class TreeNode {
      public:
        const K & key;
        const D & data;
        TreeNode *left, *right;
        TreeNode(const K & key, const D & data) : key(key), data(data), left(nullptr), right(nullptr) { }
    };

    TreeNode *head_;

    TreeNode *& _find(const K & key, TreeNode *& cur) const;
    TreeNode *& _iop(TreeNode *& cur) const;
    const D & _remove(TreeNode *& cur);
    void _swap(TreeNode *& a, TreeNode *& b);
};

#include "Dictionary.hpp"
