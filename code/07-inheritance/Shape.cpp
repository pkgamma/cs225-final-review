#include "Shape.h"

Shape::Shape() {
  length_ = 1;
}

Shape::Shape(double length) {
  length_ = length;
}

double Shape::getLength() const {
  return length_;
}
