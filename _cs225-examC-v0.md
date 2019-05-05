# CS225 Programming Exam C Review



# B-Tree

```c++
find(BTreeNode * subroot, K & key) {

    size_t first_larger_idx = insertion_idx(subroot->elements, key);

    if (first_larger_idx < subroot->elements.size() && 
        subroot->elements[first_larger_idx].key == key) {

        return subroot->elements[first_larger_idx].value;

    }

    if (subroot->is_leaf) {

        return V();

    } else {

        return find(subroot->children[first_larger_idx], key);

    }
}
```

# Uptree
```c++
vector<int> elems;
```

Creates n unconnected root nodes at the end of the vector.
```c++
addelements(int num) {
    for (int i = 0; i < num; i++) {
        elems.push_back(-1);
    }
}
```

Return the index of the root of the up-tree in which the parameter element resides.
```c++
find(int elem) {
    // negative numbers indicate that they are representatives (roots)
    if (elems[elem] < 0) {
        return elem;
    } else {
        return find(elems[elem]);
    }
}
```

When you setunion two disjoint sets, the smaller should point at the larger.
```c++
setunion(int a, int b) {
    int a_root = find(a);
    int b_root = find(b);
    int size = elems[a_root] + elems[b_root];

    if (elems[a_root] <= elems[b_root]) {
        elems[b_root] = a_root;
        elems[a_root] = size;
    } else {
        elems[a_root] = b_root;
        elems[b_root] = size;
    }
}
```

Return the number of nodes in the up-tree containing the element.
```c++
size(int elem) {
    if (elem >= (int)elems.size() || elem < 0) {
        return 0;
    } else {
        return elems[find(elem)] * -1;
    }
}
```

---
