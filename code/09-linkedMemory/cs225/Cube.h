#pragma once

namespace cs225 {
  class Cube {
    public:
      Cube();
      Cube(double length);
      Cube(const Cube & other);
      ~Cube();

      Cube operator+(const Cube & other) const;
      Cube & operator=(const Cube & other);

      double getVolume() const;
      double getSurfaceArea() const;
      
      void setLength(double length);

    private:
      double length_; 
  };
}