#include "Cube.h"
using cs225::Cube;

Cube *CreateCube() {
  Cube c(20);
  return &c;
}

int main() {
  Cube *c = CreateCube();
  double r = c->getVolume();
  double v = c->getSurfaceArea();
  return 0;
}
