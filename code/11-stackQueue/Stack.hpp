#include "Stack.h"

template <typename T>
void Stack<T>::push(const T & t) {
  list_.push_back(t);
}

template <typename T>
const T & Stack<T>::pop() {
  const T & data = list_.back();
  list_.pop_back();
  return data;
}

template <typename T>
bool Stack<T>::isEmpty() {
  return list_.empty();
}
