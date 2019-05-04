# CS225 Programming Exam C Review

# heaps

```c++
heapifyDown(idx) {

    if (hasAChild(idx) == false) { return; }

    size_t minChild = maxPriorityChild(idx);

    // if minChild is more "min" than index
    if (higherPiority(_elem[minChild], _elem[idx])) {
        swap(_elem[minChild], _elem[idx];
        heapifyDown(minChild);
    }
}
```

```c++
heapifyUp(idx) {

    if (idx = root()) { return; }

    size_t parent = parent(idx);

    // if index is more "min" than parent
    if (higherPiority(_elem[idx], _elem[parent])) {
        swap(elem[idx], _elem[parent]);
        heapiftUp(parent);
    }
}
```

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

# hash table

## Seperate Chaining

![](https://courses.engr.illinois.edu/cs225/sp2019/assets/notes/hashTable/sc2.jpg)

```c++
insert(K key, V value) {

    elems++;

    if (shouldResize()) { resizeTable(); }

    size_t idx = hash(key, size);

    pair<K, V> insert(key, value);

    // table is list<pair<K, V>>[size];
    table[idx].push_front(insert);
}
```

```c++
remove(K key) {

    typename list<pair<K, V>>::iterator it;

    size_t idx = hash(key, size);

    for (it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key) {

            table[idx].remove(it);
            elems--;
            return;

        }
    }
}
```

```c++
find(K key) {

    typename list<pair<K, V>>::iterator it;

    size_t idx = hash(key, size);

    for (it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key) {

            return it->second;

        }
    }
}
```

```c++
resizeTable() {

    typename list<pair<K, V>>::iterator it;

    size_t newSize = findPrime(s * size);

    list<pair<K, V>> * newTable = new list<pair<K, V>>[newSize];

    for (size_t i = 0; i < size; i++) {
        for (it = table[i].begin(); it != table[i].end(); i++) {

            size_t = newIdx = hash(key, size);
            pair<K, V> newPair(it_.first, it->second);
            newTable[newIdx].push_front(newPair);

        }
    }

    size  = newSize;
    table = newTable;
}
```

## Linear Probing

![](https://courses.engr.illinois.edu/cs225/sp2019/assets/notes/hashTable/lp4.jpg)

Flags for whether or not to probe forward when looking at a particular cell in the table.
```c++
bool * should_probe;
```

```c++
insert(K key, V value) {

    elems++;

    if (shouldResize()) { resizeTable(); }

    size_t insertIndex = hash(key, size);

    while (table[insertIndex] != NULL) {
        insertIndex = ((insertIndex + 1) % size);
    }

    table[insertIndex] = new pair<K, V>(key, value);

    should_probe[insertIndex] = true;
}
```

```c++
remove(K key) {

    int removeIndex = findIndex(key);

    if (removeIndex != -1) {
        delete table[removeIndex];
        table[removeIndex] = NULL;

        elems--;
    }
}
```

```c++
find(K & key) {

    // see below
    int idx = findIndex(key);

    if (idx != -1) {
        return table[idx]->second;
    }
    
    return V();
}
```

```c++
findIndex(K & key) {

    size_t findIndex = hash(key, size);

    size_t orgIndex = findIndex;

    while (should_probe[findIndex] == true) {

        if (table[findIndex]->first == key) {    
            return findIndex;
        }

        findIndex = (findIndex + 1) % size;

        if (findIndex == orgIndex) {
            break;
        }

    }

    return -1;
}
```

```c++
resizeTable() {

    size_t newSize = findPrime(size * 2);

    pair<K, V>** resizeTemp = new pair<K, V>*[newSize];

    delete[] should_probe;
    should_probe = new bool[newSize];

    for (size_t i = 0; i < newSize; i++) {
        resizeTemp[i] = NULL;
        should_probe[i] = false;
    }

    for (size_t i = 0; i < size; i++) {
        if (table[i]) {
            size_t index = hash(table[i]->first, newSize);
            while (resizeTemp[index] != NULL) {
                index = ((index + 1) % newSize);
            }
            resizeTemp[index] = table[i];
            should_probe[index] = true;
        }
    }

    delete[] table;
    table = resizeTemp;
    size = newSize;

}
```

## Double Hashing

```c++
insert(K & key, V & value) {

    elems++;

    if (shouldResize()) {
        resizeTable();
    }

    size_t insertIndex = hashes::hash(key, size);
    size_t secondHash  = hashes::secondary_hash(key, size);

    while (table[insertIndex] != NULL) {
        insertIndex = ((insertIndex + secondHash) % size);
    }

    table[insertIndex] = new pair<K, V>(key, value);

    should_probe[insertIndex] = true;
}
```

```c++
remove(K & key) {

    int removeIndex = findIndex(key);

    if (removeIndex != -1) {
        delete table[removeIndex];
        table[removeIndex] = NULL;
        elems--;
    }
}
```

```c++
find(K & key) const {
    int idx = findIndex(key);
    if (idx != -1) return table[idx]->second;
    return V();
}
```

```c++
findIndex(K & key) {

    size_t findIndex  = hashes::hash(key, size);
    size_t secondHash = hashes::secondary_hash(key, size);
    size_t orgIndex   = findIndex;

    while (should_probe[findIndex]) {

        if (table[findIndex]->first == key) {
            return findIndex;
        }

        findIndex = (findIndex + secondHash) % size;

        if (findIndex == orgIndex) {
            break;
        }
    }

    return -1;
}
```

```c++
resizeTable() {

    size_t newSize = findPrime(size * 2);

    pair<K, V>** temp = new pair<K, V>*[newSize];

    // create a new should_probe that fits the new size
    delete[] should_probe;
    should_probe = new bool[newSize];

    // init the new table we created
    for (size_t i = 0; i < newSize; i++) {
        temp[i] = NULL;
        should_probe[i] = false;
    }

    for (size_t slot = 0; slot < size; slot++) {

        if (table[slot] != NULL) {

            size_t h    = hashes::hash(table[slot]->first, newSize);
            size_t jump = hashes::secondary_hash(table[slot]->first, newSize);
            size_t i    = 0;
            size_t idx  = h;

            while (temp[idx] != NULL) {
                ++i;
                idx = (h + jump * i) % newSize;
            }

            temp[idx] = table[slot];
            should_probe[idx] = true;
        }
    }

    delete[] table;
    
    table = temp;
    size = newSize;
}
```