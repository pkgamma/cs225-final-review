#include "Cube.h"
#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

namespace cs225 {
  Cube::Cube() {
    length_ = 1;
    cout << "Cube::Cube() invoked" << endl;
  }
  
  Cube::Cube(double length) {
    length_ = length;
    cout << "Cube::Cube(double) invoked" << endl;
  }

  Cube::Cube(const Cube & other) {
    length_ = other.length_;
    cout << "Cube::Cube(const Cube &) invoked" << endl;
  }

  Cube::~Cube() {
    cout << "Cube::~Cube() invoked" << endl;    
  }

  Cube Cube::operator+(const Cube & other) const {
    double volume = length_ + other.length_;
    double newVolumne = std::pow(volume, 1.0/3.0);
    return Cube(newVolumne);
  }

  Cube & Cube::operator=(const Cube & other) {
    length_ = other.length_;
    cout << "Cube::operator=(const Cube &) invoked" << endl;    
    return *this;
  }

  double Cube::getVolume() const {
    return length_ * length_ * length_;
  }

  double Cube::getSurfaceArea() const {
    return 6 * length_ * length_;
  }

  void Cube::setLength(double length) {
    length_ = length;
  }
}