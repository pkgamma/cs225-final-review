#pragma once

namespace cs225 {
  class Cube {
    public:
      Cube();
      Cube(double length);

      double getVolume();
      double getSurfaceArea();
      void setLength(double length);

    private:
      double length_; 
  };
}