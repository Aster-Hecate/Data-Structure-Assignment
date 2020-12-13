#include <iostream>
#include "../lib/requisitories.h"
#include "../lib/graph_class.h"

using namespace std;

int main() {
  List<int> a;
  for (int i = 0; i < 10; i++) {
    a.push(i * 2 + 1);
  }
  a.deleteThisNode(2);
  cout << "length of a: "<< a.len << "\n";
  for (int i = 0; i < a.len; i++) {
    cout << "a[" << i <<"]: " << a[i] << "\n";
  }
  cout << "remaining length of a:" << a.len << "\n";
  cout << a[2];
  return 0;
}