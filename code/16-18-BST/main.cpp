/**
 * An empty BinaryTree.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Dictionary.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Dictionary<int, std::string> t;
  t.insert(37, "thirty four");
  t.insert(19, "ninteen");
  t.insert(51, "fifty one");
  t.insert(55, "fifty five");
  t.insert(4, "four");
  t.insert(11, "eleven");
  t.insert(20, "twenty");
  t.insert(2, "two");

  cout << "t.find(51): " << t.find(51) << endl;  

  cout << "t.remove(11): " << t.remove(11) << " (zero child remove)" << endl;
  cout << "t.remove(51): " << t.remove(51) << " (one child remove)" << endl;
  cout << "t.remove(19): " << t.remove(19) << " (two child remove)" << endl;

  cout << "t.find(51): " << t.find(51) << endl;
  return 0;
}