#include "Square.h"
#include "Shape.h"

Square::Square() { }

Square::Square(double length) : Shape(length) { }

double Square::getArea() const {
  return getLength() * getLength();
}