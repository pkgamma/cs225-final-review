
#include <iostream>

class Cube {
  public:
    ~Cube() { std::cout << "~Cube() invoked." << std::endl; }
};

class RubikCube : public Cube {
  public:
    ~RubikCube() { std::cout << "~RubikCube() invoked." << std::endl; }
};


class CubeV {
  public:
    virtual ~CubeV() { std::cout << "~CubeV() invoked." << std::endl; }
};

class RubikCubeV : public CubeV {
  public:
    ~RubikCubeV() { std::cout << "~RubikCubeV() invoked." << std::endl; }
};


int main() {
    std::cout << "Non-virtual dtor:" << std::endl;
    Cube *ptr = new RubikCube();
    delete ptr;

    std::cout << "Virtual dtor:" << std::endl;
    CubeV *ptrV = new RubikCubeV();
    delete ptrV;

    return 0;
}