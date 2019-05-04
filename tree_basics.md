# Binary Trees

Each node has **at most** 2 children.

## Full Tree

Each node has either 2 or 0 children.

## Perfect Tree

Full tree + all leaves same distance from root.

## Complete Tree

Full tree + perfect tree except last level, where all leaves are "pushed to the left."

<img src="img/tree.png" width="50%">

# Traversal

To **traverse** a tree means we process every element exactly once in a tree.

```cpp
// pre-order

void BinaryTree<T>::preOrder(TreeNode * cur) {
  if (cur != NULL) {
    print(cur->data);     // print is some imaginary function
    preOrder(cur->left);
    preOrder(cur->right);
  }
}
```

```cpp
// in-order

void BinaryTree<T>::inOrder(TreeNode * cur) {
  if (cur != NULL) {
    inOrder(cur->left);
    print(cur->data); 
    inOrder(cur->right);
  }
}
```

```cpp
// post-order

void BinaryTree<T>::postOrder(TreeNode * cur) {
  if (cur != NULL) {
    postOrder(cur->left);
    postOrder(cur->right);
    print(cur->data);  
  }
}
```

# Search

## BFS

- Visit nearby nodes quickly by each level.
- In other words, visit the direct descendants quicker (level-order traversal).

<img src="img/tree_bfs.png" width="50%">

## DFS

- Find the endpoint of a path quickly, and to move deeper into the tree as quickly as possible.
- In other words, we visit the leaves as soon as possible. 

<img src="img/tree_dfs.png" width="50%">