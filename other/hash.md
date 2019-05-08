# Hashing

- The hash function: f(h) -> Integers
- The compression: Integer -> array
- Handling collisions

## Resolving Collisions

### Seperate Chaining

<img src="img/hash_sc.jpg" width="500px">

```cpp
void insert(K key, V value) {

    elems++;

    if (shouldResize()) { resizeTable(); }

    size_t idx = hash(key, size);

    pair<K, V> insert(key, value);

    // table is list<pair<K, V>>[size];
    table[idx].push_front(insert);
}
```

```cpp
void remove(K key) {

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

```cpp
V find(K key) {

    typename list<pair<K, V>>::iterator it;

    size_t idx = hash(key, size);

    for (it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key) {

            return it->second;

        }
    }
}
```

```cpp
void resizeTable() {

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

### Linear Probing

<img src="img/hash_lp.jpg" width="500px">

Flags for whether or not to probe forward when looking at a particular cell in the table.
```cpp
bool * should_probe;
```

```cpp
void insert(K key, V value) {

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

```cpp
void remove(K key) {

    int removeIndex = findIndex(key);

    if (removeIndex != -1) {
        delete table[removeIndex];
        table[removeIndex] = NULL;

        elems--;
    }
}
```

```cpp
V find(K & key) {

    // see below
    int idx = findIndex(key);

    if (idx != -1) {
        return table[idx]->second;
    }
    
    return V();
}
```

```cpp
int findIndex(K & key) {

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

```cpp
void resizeTable() {

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

### Double Hashing

```cpp
void insert(K & key, V & value) {

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

```cpp
void remove(K & key) {

    int removeIndex = findIndex(key);

    if (removeIndex != -1) {
        delete table[removeIndex];
        table[removeIndex] = NULL;
        elems--;
    }
}
```

```cpp
V find(K & key) const {
    int idx = findIndex(key);
    if (idx != -1) return table[idx]->second;
    return V();
}
```

```cpp
int findIndex(K & key) {

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

```cpp
void resizeTable() {

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