/**
 * Simple C++ program using variables.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include <iostream>
#include "Cube.h"

int main() {
  cs225::Cube c;
  std::cout << "Volume: " << c.getVolume() << std::endl;

  return 0;
}