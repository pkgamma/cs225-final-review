# Heaps (Priority Queues)

Whenever remove is called, the data structure pops out an element with a predetermined property (for example, the smallest element in minHeap).

## minHeap

- Map level order tree traversal to an array or vector.
- Use trees just for representation.
- Root starts at `1` for convenience.

<img src="img/minheap.png" width="500px">

## heapifyUp

```cpp
void heapifyUp(idx) {

    if (idx = root()) { return; }

    size_t parent = parent(idx);

    // if index is more "min" than parent
    if (higherPiority(_elem[idx], _elem[parent])) {
        swap(elem[idx], _elem[parent]);
        heapiftUp(parent);
    }
}
```

## heapifyDown

```cpp
void heapifyDown(idx) {

    if (hasAChild(idx) == false) { return; }

    size_t minChild = maxPriorityChild(idx);

    // if minChild is more "min" than index
    if (higherPiority(_elem[minChild], _elem[idx])) {
        swap(_elem[minChild], _elem[idx];
        heapifyDown(minChild);
    }
}
```