#pragma once

#include "cs225/Cube.h"

class RubikCube : public cs225::Cube {
  public:
    void solve();

    void turnRow(int r);
    void turnColumn(int c);
    void rotate(int direction);

  private:
    // ...
    // Not implemented
};

