#include "AVL.h"
#include <stdexcept>
#include <iostream>
#include <utility>

int max(int a, int b) {
  if (a > b) { return a; }
  else       { return b; }
}


/**
 * Default constructor that creates an empty AVL.
 */ 
template <typename K, typename D>
AVL<K, D>::AVL() : root_(nullptr) {
  // Empty
}


/**
 * Finds the data associated with a given key in the AVL.
 */
template <typename K, typename D>
const D & AVL<K, D>::find(const K & key) {
  TreeNode *& node = _find(key, root_);
  if (node == nullptr) { throw std::runtime_error("key not found"); }
  return node->data;
}


/**
 * Inserts `key` and associated `data` into the AVL.
 */ 
template <typename K, typename D>
void AVL<K, D>::insert(const K & key, const D & data) {
  _insert(key, data, root_);
}


/**
 * Removes `key` from the AVL.  Returns the associated data.
 */ 
template <typename K, typename D>
const D & AVL<K, D>::remove(const K & key) {
  const D & d = _findAndRemove(key, root_);
  return d;
}


/**
 * Returns the height of a given `TreeNode` or -1 on `nullptr`.
 */ 
template <typename K, typename D>
int AVL<K, D>::height(TreeNode *& cur) {
  if (cur == nullptr) { return -1; }
  else                { return cur->height; }
}


/**
 * Completes a right rotation on a tree rooted at `cur`.
 */
template <typename K, typename D>
void AVL<K, D>::_rotateRight(TreeNode *& cur) {
  TreeNode *x = cur;
  TreeNode *y = cur->left;

  x->left = y->right;
  y->right = x;
  cur = y;

  _updateHeight(x);
  _updateHeight(y);
}


/**
 * Completes a left rotation on a tree rooted at `cur`.
 */
template <typename K, typename D>
void AVL<K, D>::_rotateLeft(TreeNode *& cur) {
  TreeNode *x = cur;
  TreeNode *y = cur->right;

  x->right = y->left;
  y->left = x;
  cur = y;

  _updateHeight(x);
  _updateHeight(y);
}


/**
 * Completes a right-left rotation on a tree rooted at `cur`.
 */
template <typename K, typename D>
void AVL<K, D>::_rotateRightLeft(TreeNode *& cur) {
  _rotateRight(cur->right);
  _rotateLeft(cur);
}


/**
 * Completes a left-right rotation on a tree rooted at `cur`.
 */
template <typename K, typename D>
void AVL<K, D>::_rotateLeftRight(TreeNode *& cur) {
  _rotateLeft(cur->left);
  _rotateRight(cur);
}


/**
 * Ensures that `cur` is balanced.  If not, a rotation is performed
 * to re-balance `cur`.
 */
template <typename K, typename D>
void AVL<K, D>::_ensureBalance(TreeNode *& cur) {
  // Calculate the balance factor:
  int balance = height(cur->right) - height(cur->left);

  // Check if the node is current not in balance:
  if ( balance == -2 ) {
    int l_balance = height(cur->left->right) - height(cur->left->left);
    if ( l_balance == -1 ) { _rotateRight( cur ); }
    else                   { _rotateLeftRight( cur ); }
  } else if ( balance == 2 ) {
    int r_balance = height(cur->right->right) - height(cur->right->left);
    if( r_balance == 1 ) { _rotateLeft( cur ); }
    else                 { _rotateRightLeft( cur ); }
  }

  _updateHeight(cur);
}


/**
 * Updates the height of `cur` based on the height of `cur`'s children.
 */
template <typename K, typename D>
void AVL<K, D>::_updateHeight(TreeNode *& cur) {
  cur->height = 1 + max(height(cur->left), height(cur->right));
}


/**
 * Recursive BST insert with a balance check at each level.
 */
template <typename K, typename D>
void AVL<K, D>::_insert(const K & key, const D & data, TreeNode *& cur) {
  if ( cur == NULL ) {
    // Found a leaf, add node:
    cur = new TreeNode(key, data);
    // std::cerr << "After insert: " << *root_ << std::endl;
  } else if ( key < cur->key ) {
    // Recurse into left child:
    _insert( key, data, cur->left );
  } else if ( key > cur->key ) {
    // Recurse into right child:
    _insert( key, data, cur->right );
  }
  
  // Ensure balance:
  _ensureBalance(cur);
}


/**
 * Recusive helper function for finding the TreeNode containing a given key.
 * Returns a reference to a `nullptr` if the key is not found.
 * 
 * Note that this functions returns a `TreeNode` pointer by reference (TreeNode *&).
 * - This reference is an alias to the pointer that points to TreeNode that contains the key.
 * - For example, if the key is contained the root of the tree, the pointer reference returned
 *   is a reference to the root pointer.  By changing the returned referece, the root of the
 *   tree is changed.
 */
template <typename K, typename D>
typename AVL<K, D>::TreeNode *& AVL<K, D>::_find(const K & key, TreeNode *& cur) const {
  if (cur == nullptr)       { return cur; }
  else if (key == cur->key) { return cur; }
  else if (key <  cur->key) { return _find(key, cur->left); }
  else                      { return _find(key, cur->right); }
}


template <typename K, typename D>
const D & AVL<K, D>::_findAndRemove(const K & key, TreeNode *& cur) {
  if (cur == nullptr)       { throw std::runtime_error("delete key not found"); }
  else if (key == cur->key) { return _remove(cur); }
  else if (key <  cur->key) {
    const D & data = _findAndRemove(key, cur->left);
    _ensureBalance(cur);
    return data;
  } else {
    const D & data = _findAndRemove(key, cur->right);
    _ensureBalance(cur);
    return data;
  }
}


/**
 * Swaps the child pointers of `a` and `b` within the BST.
 */ 
template <typename K, typename D>
void AVL<K, D>::_swap(TreeNode *& a, TreeNode *& b) {
  TreeNode *c_left = a->left;
  TreeNode *c_right = a->right;

  a->left = b->left;
  a->right = b->right;

  b->left = c_left;
  b->right = c_right;
}


/**
 * Recursive IoP remove.
 */ 
template <typename K, typename D>
const D & AVL<K, D>::_iopRemove(TreeNode *& node, TreeNode *& iop) {
  if (iop->right != nullptr) {
    // IoP not found, keep going deeper:
    const D & d = _iopRemove(node, iop->right);
    if (iop) { _ensureBalance(iop); }
    return d;
  } else {
    // Found IoP, swap the location:
    _swap( node, iop );
    std::swap( node, iop );

    // Remove the swapped node (at iop's position):
    return _remove(iop);
  }
}

/**
 * Removes `node` from the BST.
 */
template <typename K, typename D>
const D & AVL<K, D>::_remove(TreeNode *& node) {
  D const * data;

  // Zero child remove:
  if (node->left == nullptr && node->right == nullptr) {
    // std::cerr << "Zero child remove: " << *node << std::endl;
    data = &node->data;
    delete(node);
    node = nullptr;
  }

  // One-child (left) remove
  else if (node->left != nullptr && node->right == nullptr) {
    // std::cerr << "One child remove (left): " << *node << std::endl;
    data = &node->data;
    TreeNode *temp = node;
    node = node->left;
    delete(temp);
  }

  // One-child (right) remove
  else if (node->left == nullptr && node->right != nullptr) {
    // std::cerr << "One child remove (right): " << *node << std::endl;
    data = &node->data;
    TreeNode *temp = node;
    node = node->right;
    delete(temp);
  }

  // Two-child remove:
  else {
    //std::cerr << "Two child remove: " << *node << std::endl;
    data = &_iopRemove( node, node->left );
    _ensureBalance(node);
  }

  //if (node) { std::cerr << "AFTER _remove(): " << *node << std::endl; }
  return *data;
}
