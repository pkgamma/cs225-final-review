/**
 * An empty BinaryTree.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "AVL.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;

int main() {
  AVL<int, std::string> avl;

  avl.insert(37, "thirty four");
  avl.insert(19, "ninteen");
  avl.insert(51, "fifty one");
  avl.insert(55, "fifty five");
  avl.insert(4, "four");
  avl.insert(11, "eleven");
  avl.insert(20, "twenty");
  avl.insert(2, "two");
  avl.insert(3, "three");
  avl.insert(5, "five");
  avl.insert(6, "six");
  avl.insert(7, "seven");

  cout << "avl.find(51): " << avl.find(51) << endl;  

  cout << "avl.remove(11): " << avl.remove(11) << endl;
  cout << "avl.remove(51): " << avl.remove(51) << endl;
  cout << "avl.remove(19): " << avl.remove(19) << endl;
  cout << "avl.remove(6): " << avl.remove(6) << endl;

  cout << "avl.find(51): " << avl.find(51) << endl;
  return 0;
}