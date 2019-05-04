/**
 * Simple linked-memory, templated list class.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

template <typename T>
class List {
  public:
    List() : head_(nullptr) { }
    const T & operator[](unsigned index);
    void insertAtFront(const T & data);
    void printReverse() const;    
    void insert(const T & data, unsigned index);
    const T & remove(unsigned index);

  private:
    class ListNode {
      public:
        const T & data;
        ListNode *next;
        ListNode(const T & data) : data(data), next(nullptr) { }
    };

    ListNode *head_;   /*< Head pointer for our List */
    
    ListNode *_find(const T & data);
    void _printReverse(ListNode *node) const;
    ListNode *& _index(unsigned index);
    ListNode *& _index_helper(unsigned index, ListNode *& node);
};

#include "List.hpp"