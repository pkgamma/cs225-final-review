#include "Cube.h"
using cs225::Cube;

#include <iostream>
using std::cout;
using std::endl;

int main() {
  Cube *c1 = new Cube();
  Cube *c2 = c1;

  cout << "&s1: " << &c1 << endl;
  cout << "&s2: " << &c2 << endl;

  cout << " s1: " << c1 << endl;
  cout << " s2: " << c2 << endl;

  return 0;
}
