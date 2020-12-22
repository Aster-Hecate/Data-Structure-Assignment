#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#define HEADERS_READY

#include "../lib/requisitories.h"
#include "../lib/graph_class.h"

using namespace std;

int main() {
  
  ifstream IF;
  IF.open("test");
  Graph<int> g;
  g.init(IF);
  cout << "YES";
  IF.close();

  
}