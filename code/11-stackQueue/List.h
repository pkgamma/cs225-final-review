/**
 * Simple array-based list.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

template <typename T>
class List {
  public:
    // ..
  private:
    T * arr_;
    unsigned capacity_;
    unsigned size_;
};

#include "List.hpp"