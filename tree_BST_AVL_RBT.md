# BST Tree (Binary Search Tree)

Binary tree but
- Everything to the left of root < root
- Everything to the right of root > root

## Find

```cpp
// Find

TreeNode *& _find(TreeNode *& root, const K & key) const {
     If (root == NULL || key == root->key) {
          return root;  //root is null when we cannot find
     }
     If (key < root->key) {
          return _find(root->left, key);
     }
     If (key > root->key) {
          return _find(root->right, key);
     }
}
```

## Remove

- No child: Just remove
- 1 child: Swap with child then remove
- 2 children: Swap with IOP then remove, like this:

1. Find inorder predecessor (IOP), the largest node in the left subtree (the rightmost node).
2. Swap IOP and the node we want to delete.
3. The node is now a leaf, so we can remove it.

<!-- <img src="img/bst_remove_1.png" width="250px">
<img src="img/bst_remove_2.png" width="250px">
<img src="img/bst_remove_3.png" width="250px"> -->

## BST Analysis

| Operation | BST Average Case | BST Worst Case | Sorted Array                      | Sorted List              |
| --------- | ---------------- | -------------- | --------------------------------- | ------------------------ |
| find      | O(lg n)          | O(h) <= O(n)   | O(lg n) with binary search        | O(n) no binary search    |
| insert    | O(lg n)          | O(h) <= O(n)   | O(n) with find O(lg n), move O(n) | O(n) find data with O(n) |
| delete    | O(lg n)          | O(h) <= O(n)   | O(n)                              | O(n)                     |
| traverse  | O(n)             | O(n)           | O(n)                              | O(n)                     |

## Balance Factor

b = height(TR) - height(TL)

- left heavy: b negative
- right heavy: b positive
- balanced: if |b| <= 1
- lowest point of imbalance: the deepest node in the tree that is out of balance

## BST Rotation

- 4 kinds of rotation (L, R, LR, RL)
  - Simple rotations: **stick**
  - Complex rotations: **elbow**
- All rotations local
- All rotations run in O(1)

<img src="img/avl_rotate.jpg" width="500px">

# AVL Tree

**Self-Balancing BST** where the difference between heights of left and right subtrees cannot be more than 1.

To maintain height of tree:
1. Check for imbalance.
2. Correct it (do rotations).
3. Update height.

## Running Time

- **O(lg(n))** for all operations.

## Number of Rotations

- Find: 0
- Insert: up to 1 (L, R, LR, or RL)
- Delete: up to h (O(lg(n)))

# Red Black Tree

- Almost the same as AVL Trees.
- Maximal height is 2 * lg(n) = O(lg(n)).

# Summary: Every Data Structure So Far

| Worst runtime | Unsorted Array                      | Sorted Array               | Unsorted List    | Sorted List | Binary Tree (unsorted) | BST     | AVL     |
| ------------- | ----------------------------------- | -------------------------- | ---------------- | ----------- | ---------------------- | ------- | ------- |
| find          | O(n)                                | O(lg n) Binary search      | O(n)             | O(n)        | O(n)                   | O(h)<=n | O(lg n) |
| insert        | O(1)* InsertEnd and resize properly | O(n) Shifting up to ½ data | O(1) InsertFront | O(n)        | O(1) Insert at root    | O(h)<=n | O(lg n) |
| remove        | O(n)                                | O(n)                       | O(n)             | O(n)        | O(n)                   | O(h)<=n | O(lg n) |
| traverse      | O(n)                                | O(n)                       | O(n)             | O(n)        | O(n)                   | O(n)    | O(n)    |

*: amortized runtime