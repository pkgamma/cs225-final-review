#include <iostream>
using std::cout;
using std::endl;

// Cube class:
class Cube {
  public:
    void print_1() {
      cout << "Cube" << endl;
    }

    void print_2() {
      cout << "Cube" << endl;
    }

  virtual void print_3() {
    cout << "Cube" << endl;
  }

  virtual void print_4() {
    cout << "Cube" << endl;
  }

  virtual void print_5() = 0;
};

// RubikCube class:
class RubikCube : public Cube {
  public:
    // No print_1()

    void print_2() {
      cout << "Rubik" << endl;
    }

    // No print_3()

    virtual void print_4() {
      cout << "Rubik" << endl;
    }

    void print_5() {
      cout << "Rubik" << endl;
    }
};

int main() {
  // Column 1:
  {
    // Will not compile -- cannot have an instance of a pure virtual!
    /*
    Cube c;
    c.print_1();
    c.print_2();
    c.print_3();
    c.print_4();
    c.print_5();
    */
  }
  cout << " ----- ";

  // Column 2:
  {
    RubikCube c;
    c.print_1();
    c.print_2();
    c.print_3();
    c.print_4();
    c.print_5();
  }
  cout << " ----- ";

  // Column 1:
  {
    RubikCube rc;
    Cube &c = rc;
    c.print_1();
    c.print_2();
    c.print_3();
    c.print_4();
    c.print_5();
  }

  return 0;
}
