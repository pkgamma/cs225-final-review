#include "cs225/Cube.h"
using cs225::Cube;

Cube *CreateCube() {
  Cube c(20);
  return &c;
}

int main() {
  Cube *c = CreateCube();
  //SomeOtherFunction();
  double v = c->getVolume();
  double a = c->getSurfaceArea();
  return 0;
}
