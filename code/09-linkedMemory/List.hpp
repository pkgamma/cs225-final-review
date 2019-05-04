/**
 * Simple linked-memory, templated list class.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include <iostream>
#include "List.h"

template <typename T>
void List<T>::insertAtFront(const T & data) {
  // Create a new ListNode on the heap:
  ListNode *node = new ListNode(data);

  // Set the new node’s next pointer point the current
  // head of the List:
  node->next = head_;

  // Set the List’s head pointer to be the new node:
  head_ = node;
}


template <typename T>
void List<T>::printReverse() const {
  _printReverse(head_);
}

template <typename T>
void List<T>::_printReverse(ListNode *node) const {
  if (node != nullptr) {
    _printReverse(node->next);
    std::cout << node->data << std::endl;
  }
}


template <typename T>
const T & List<T>::operator[](unsigned index) const {
  // Use _index to return the ListNode* at a given index:
  ListNode * node = _index(index);

  // Return the data:
  return node->data;
}

template <typename T>
typename List<T>::ListNode * List<T>::_index(unsigned index) const {
  // Start a `thru` pointer to advance thru the list:
  ListNode *thru = head_;

  // Loop until the end of the list (or until a `nullptr`):
  while (index > 0 && thru->next != nullptr) {
    thru = thru->next;
    index--;
  }  

  // Return the ListNode:
  return thru;
}


/**
 * Finds and returns the ListNode containing `data` in the
 * List or `nullptr` if the data is not found.
 */
template <typename T>
typename List<T>::ListNode * List<T>::_find(const T & data) {
  ListNode *thru = head_;
  while (thru != nullptr) {
    if (thru->data == data) { return thru; }
  }

  return nullptr;  
}