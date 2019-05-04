#include "cs225/Cube.h"
using cs225::Cube;

int main() {
  Cube *c1 = new Cube();
  Cube *c2 = c1;
  c2->setLength( 10 );
  delete c2;
  delete c1;
  return 0;
}