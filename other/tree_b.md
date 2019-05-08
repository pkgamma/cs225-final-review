# B Tree (of order `m`)

- Each node holes 2 arrays
  - first holds the keys of the node
  - second holds pointers to the children

<img src="img/btree.png" width="500px">

## Properties

- Keys within a node are ordered
- Leaves contain no more than `m-1` keys
- Internal nodes have exactly one more child than keys
- Root nodes can have `2` to `m` children
- Internal nodes can have `ceil(m/2)` to `m` children
- All leaves are at the same depth, which makes the tree balanced

## Find

```cpp
template <class K, class V>
V BTree<K, V>::find(const BTreeNode* subroot, const K& key) const
{
    /* If first_larger_idx is a valid index and the key there is the key we
     * are looking for, we are done. */

    /* Otherwise, we need to figure out which child to explore. For this we
     * can actually just use first_larger_idx directly. E.g.
     * | 1 | 5 | 7 | 8 |
     * Suppose we are looking for 6. first_larger_idx is 2. This means we want to
     * explore the child between 5 and 7. The children vector has a pointer for
     * each of the horizontal bars. The index of the horizontal bar we want is
     * 2, which is conveniently the same as first_larger_idx. If the subroot is
     * a leaf and we didn't find the key in it, then we have failed to find it
     * anywhere in the tree and return the default V.
     */

    size_t first_larger_idx = insertion_idx(subroot->elements, key);

    if (first_larger_idx < subroot->elements.size() && subroot->elements[first_larger_idx].key == key) {
        return subroot->elements[first_larger_idx].value;
    }

    if (subroot->is_leaf) {
        return V();
    } else {
        return find(subroot->children[first_larger_idx], key);
    }
}
```

## Runtime

- Search: `O(log n)`
- Combining/Splitting of Keys: `O(m)`
- Insert/Delete: `O((m/log m) * log n)`