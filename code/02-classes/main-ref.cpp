#include <iostream>

int main() {
  int i = 7;
  int & j = i;   // j is an alias of i

  j = 4;  std::cout << i << " " << j << std::endl;

  i = 2;
  std::cout << i << " " << j << std::endl;
  return 0;
}
