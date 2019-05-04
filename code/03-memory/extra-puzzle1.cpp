#include <iostream>
using std::cout;
using std::endl;

int main() {
  int *p;
  int x;

  p = &x;
  x = 6;

  cout << x << endl;
  cout << p << endl;

  return 0;
}
