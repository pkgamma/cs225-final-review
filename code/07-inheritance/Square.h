#pragma once

#include "Shape.h"

class Square : public Shape {
  public:
    Square();
    Square(double length);
    double getArea() const;
  private:
    // Nothing!
};

