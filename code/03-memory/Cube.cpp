#include "Cube.h"

namespace cs225 {
  Cube::Cube() {
    length_ = 1;
  }
  
  Cube::Cube(double length) {
    length_ = length;
  }

  double Cube::getVolume() {
    return length_ * length_ * length_;
  }

  double Cube::getSurfaceArea() {
    return 6 * length_ * length_;
  }

  void Cube::setLength(double length) {
    length_ = length;
  }
}