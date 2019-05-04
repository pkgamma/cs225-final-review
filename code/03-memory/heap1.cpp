#include "Cube.h"
using cs225::Cube;

#include <iostream>
using std::cout;
using std::endl;

int main() {
  int *p = new int;
  Cube *c = new Cube(10);

  cout << "&p: " << &p << endl;
  cout << "&s: " << &c << endl;

  cout << " p: " << p << endl;
  cout << " c: " << c << endl;

  return 0;
}
