#include <iostream>

#include "../lib/requisitories.h"

using namespace std;

int main() {
  List<int> a;
  unit<int> *n = a.head;
  a.append(1);
  a.append(12);
  n = n->next->next;
  cout << a[1];
  return 0;
}