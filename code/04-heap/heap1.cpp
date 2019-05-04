#include "cs225/Cube.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
  int *p = new int;
  cs225::Cube *c = new cs225::Cube(10);

  cout << "&p: " << &p << endl;
  cout << "&c: " << &c << endl;

  cout << " p: " << p << endl;
  cout << " c: " << c << endl;

  return 0;
}