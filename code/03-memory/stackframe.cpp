#include <iostream>
using namespace std;

int hello() {
  int a = 100;
  cout << "hello() - &a: " << &a << endl;
  return a;
}

int main() {
  int a;
  int b = -3;
  int c = hello();
  int d = 42;

  cout << "main() - &a: " << &a << endl;
  cout << "main() - &b: " << &b << endl;
  cout << "main() - &c: " << &c << endl;
  cout << "main() - &d: " << &d << endl;

  return 0;
}
