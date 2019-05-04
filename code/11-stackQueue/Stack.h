#pragma once

#include <vector>

template <typename T>
class Stack {
  public:
    void push(const T & t);
    const T & pop();
    bool isEmpty();

  private:    
    std::vector<T> list_;
};

#include "Stack.hpp"