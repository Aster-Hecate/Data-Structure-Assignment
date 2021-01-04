#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#define HEADERS_READY

#include "lib/requisitories.h"
#include "lib/graph_class.cpp"
#include "lib/dijkstra.cpp"

using namespace std;

int main() {
  
  ifstream IF;
  IF.open("example.graph");
  Graph<int> g;
  g.init(IF);
  unitSet *uspt = optimize(g, "A");
  IF.close();
  delete[] uspt;
  
}