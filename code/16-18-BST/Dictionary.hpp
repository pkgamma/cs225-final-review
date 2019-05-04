#include "Dictionary.h"
#include <stdexcept>

/**
 * Dictionary()
 * Default constructor that creates an empty dictionary.
 */ 
template <typename K, typename D>
Dictionary<K, D>::Dictionary() : head_(nullptr) {
  // Empty
}


/**
 * find()
 * Finds the data associated with a given key in the dictionary.
 */
template <typename K, typename D>
const D & Dictionary<K, D>::find(const K & key) {
  TreeNode *& node = _find(key, head_);
  if (node == nullptr) { throw std::runtime_error("key not found"); }
  return node->data;
}


/**
 * insert()
 * Inserts `key` and associated `data` into the Dictionary.
 */ 
template <typename K, typename D>
void Dictionary<K, D>::insert(const K & key, const D & data) {
  TreeNode *& node = _find(key, head_);
  node = new TreeNode(key, data);
}


/**
 * remove()
 * Removes `key` from the Dictionary.  Returns the associated data.
 */ 
template <typename K, typename D>
const D & Dictionary<K, D>::remove(const K & key) {
  TreeNode *& node = _find(key, head_);
  return _remove(node);
}



/**
 * _find()
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
typename Dictionary<K, D>::TreeNode *& Dictionary<K, D>::_find(const K & key, TreeNode *& cur) const {
  if (cur == nullptr)       { return cur; }
  else if (key == cur->key) { return cur; }
  else if (key <  cur->key) { return _find(key, cur->left); }
  else                      { return _find(key, cur->right); }
}



/**
 * _iop()
 * Returns a reference to a pointer pointing to the right-most TreeNode from `cur`.
 */ 
template <typename K, typename D>
typename Dictionary<K, D>::TreeNode *& Dictionary<K, D>::_iop(TreeNode *& cur) const {
  if (cur->right != nullptr) { return _iop(cur->right); }
  else                       { return cur; }
}


/**
 * _swap()
 * Swaps the location of `a` and `b` within the BST.
 */ 
template <typename K, typename D>
void Dictionary<K, D>::_swap(TreeNode *& a, TreeNode *& b) {
  TreeNode *c_left = a->left;
  TreeNode *c_right = a->right;

  a->left = b->left;
  a->right = b->right;

  b->left = c_left;
  b->right = c_right;
}


/**
 * _remove()
 * Removes a `node` from the BST.
 */
template <typename K, typename D>
const D & Dictionary<K, D>::_remove(TreeNode *& node) {
  // Zero child remove:
  if (node->left == nullptr && node->right == nullptr) {
    const D & data = node->data;
    delete(node);
    node = nullptr;
    return data;
  }

  // One-child (left) remove
  else if (node->left != nullptr && node->right == nullptr) {
    const D & data = node->data;
    TreeNode *temp = node;
    node = node->left;
    delete(temp);
    return data;
  }

  // One-child (right) remove
  else if (node->left == nullptr && node->right != nullptr) {
    const D & data = node->data;
    TreeNode *temp = node;
    node = node->right;
    delete(temp);
    return data;
  }

  // Two-child remove:
  else {
    // Find the IOP
    TreeNode *& iop = _iop( node->left );
    
    // Swap the node to remove and the IOP
    _swap( node, iop );
    
    // Remove the new IOP node that was swapped
    return _remove( node );
  }
}


