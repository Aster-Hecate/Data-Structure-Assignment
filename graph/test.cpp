#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#define HEADERS_READY

#include "../lib/requisitories.h"
#include "../lib/graph_class.cpp"
#include "dijkstra.cpp"

using namespace std;

int main() {
  
  ifstream IF;
  IF.open("test");
  Graph<int> g;
  g.init(IF);
  unitSet *us = optimize(g, "A");
  IF.close();

  
}