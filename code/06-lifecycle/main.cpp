#include "cs225/Cube.h"
using cs225::Cube;

#include "Tower.h"

int main() {
    Cube c1, c2, c3;
    Tower t(c1, &c2, c3);

    return 0;
}