#include "BinaryTree.h"

#include <iostream>

template <typename T>
BinaryTree<T>::BinaryTree() : root_(NULL) { }

template <typename T>
void BinaryTree<T>::insert(T & t) {
  // A very bad insert -- we insert at the root, and place the previous
  // tree as the left sub-child.
  TreeNode *e = new TreeNode(t);
  e->left = root_;
  root_ = e;
  // --> Q: Why is this a very bad insert?
}

template <typename T>
T & BinaryTree<T>::remove() {
  throw "Not implemented";
}
