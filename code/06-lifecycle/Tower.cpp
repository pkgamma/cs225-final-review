#include "Tower.h"
#include "cs225/Cube.h"
using cs225::Cube;

Tower::Tower(Cube c, Cube *ptr, const Cube &ref) :
  cube_(c), ptr_(ptr), ref_(ref) {
  // Nothing
}

Tower::Tower(const Tower & other) : ref_(other.ref_) {
  // Deep copy cube_:
  cube_ = other.cube_;


  // Deep copy ptr_:
  ptr_ = new Cube(*other.ptr_);
  
  
  // Deep copy ref_:
  // ...no need to deep copy a `const` ref

}
