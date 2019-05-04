#pragma once

#include "cs225/Cube.h"
using cs225::Cube;

class Tower {
  public:
    Tower(Cube c, Cube *ptr, const Cube &ref);
    Tower(const Tower & other);

  private:
    Cube cube_;
    Cube *ptr_;
    const Cube &ref_;
};
