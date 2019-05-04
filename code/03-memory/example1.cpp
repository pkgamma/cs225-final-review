#include <iostream>
using namespace std;

int main() {
  int a;
  int b = -3;
  int c = 12345;

  int *p = &b;

  cout << "&a: " << &a << endl;
  cout << "&b: " << &b << endl;
  cout << "&c: " << &c << endl;
  cout << "&p: " << &p << endl;

  return 0;
}
