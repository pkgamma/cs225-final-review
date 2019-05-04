#include "Square.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
  Square sq;
  sq.getLength(); // Returns 1, the length init’d by Shape’s default ctor

  cout << "Length of `Square`: " << sq.getLength() << endl;
  
  return 0;
}

