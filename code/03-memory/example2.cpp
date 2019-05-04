#include <iostream>
#include "Cube.h"

int main() {
  cs225::Cube c;
  cs225::Cube *p = &c;

  std::cout << "&c: " << &c << std::endl;
  std::cout << "&p: " << &p << std::endl;

  return 0;
}
