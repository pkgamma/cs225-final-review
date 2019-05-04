/**
 * Simple linked-memory, templated list class.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include <iostream>
#include "List.h"

/**
 * insertAtFront
 */
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


/**
 * printReverse
 */
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


/**
 * opreator[]
 */ 
template <typename T>
const T & List<T>::operator[](unsigned index) {
  // Use _index to return the ListNode* at a given index:
  ListNode *& node = _index(index);

  // Return the data:
  return node->data;
}

template <typename T>
typename List<T>::ListNode *& List<T>::_index(unsigned index) {
  return _index_helper(index, head_);
}

template <typename T>
typename List<T>::ListNode *& List<T>::_index_helper(unsigned index, ListNode *& node) {
  if (index == 0 || node == nullptr) { return node; }
  else                               { return _index_helper(index - 1, node->next); }
}


/**
 * _find()
 * 
 * Finds and returns the ListNode containing `data` in the
 * List or `nullptr` if the data is not found.
 */
template <typename T>
typename List<T>::ListNode * List<T>::_find(const T & data) {
  ListNode *thru = head_;
  while (thru != nullptr) {
    if (thru->data == data) { return thru; }
    thru = thru->next;
  }

  return nullptr;  
}


/**
 * insert
 */
template <typename T>
void List<T>::insert(const T & data, unsigned index) {
  ListNode * newNode = new ListNode(data);
  ListNode *& node = _index(index);

  newNode->next = node;
  node = newNode;
}


/**
 * remove
 */
template <typename T>
const T & List<T>::remove(unsigned index) {
  ListNode *& node = _index(index);
  
  ListNode * temp = node;
  const T & data = temp->data;

  node = node->next;
  delete temp;

  return data;
}

