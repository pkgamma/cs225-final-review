# k-d Tree

- aka **k-dimensional tree**.
- A **BST** that organizes points in k dimensional space. 
- Every node in a k-d Tree contains one point. 
- Every parent node splits the space into two subspaces based on a certain dimension. 
- Every node in its left subtree is in the left subspace, and every node in its right subtree is in the right subspace. 
- The dimension that a node is splitting on depends on which level of the tree this node is in.
- Useful for range and nearest neighbor searches.

## Constructing a k-d Tree

### 1. Alternate splitting dimension

- Each node splits the space in a certain dimension. 
- Nodes on the i th level split the space in the i th dimension. 
- If i is greater than k, the dimension wraps back around to i mod k.

Example: a 2-d k-d tree, each node on a odd level splits the x dimension, and each node on a even level splits the y dimension:

<img src="img/kd_split.png" width="500px">

### 2. Find the median

- Each node split the space such that number of nodes in the left subspace = right subspace.
- We pick the median among the nodes for the **current dimension** and make it the subroot.

### 3. Recurse on subtrees

Given this array to construct a k-d tree:

<img src="img/kd_1.png" width="500px">

Find the median in terms of **current dimension** (dimension 1):

<img src="img/kd_2.png" width="500px">

Partition so that smaller on left, greater on right:

<img src="img/kd_3.png" width="500px">

Find the median in terms of **current dimension** (dimension 2):

<img src="img/kd_4.png" width="500px">

Repeat this process until the array only consists of one node:

<img src="img/kd_5.png" width="500px">








```
image credits: Jenny Chen (https://courses.engr.illinois.edu/cs225/sp2019/notes/kd-tree/)
```