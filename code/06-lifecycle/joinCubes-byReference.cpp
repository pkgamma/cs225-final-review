#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

#include "cs225/Cube.h"
using cs225::Cube;


/*
 * Creates a new Cube that contains the exact volume
 * of the volume of the two input Cubes.
 */
Cube joinCubes(Cube & c1, Cube & c2) {
  double totalVolume = c1.getVolume() + c2.getVolume();

  double newLength = std::pow( totalVolume, 1.0/3.0 );

  Cube result(newLength);
  return result;
}


int main() {
  Cube *c1 = new Cube(4);
  Cube *c2 = new Cube(5);

  Cube c3 = joinCubes(*c1, *c2);
  cout << "c3.getVolume(): " << c3.getVolume() << endl;

  return 0;
}
