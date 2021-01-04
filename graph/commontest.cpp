#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "menu.cpp"
using namespace std;

int main() {

  system("chcp 65001");

  ifstream IF;
  IF.open("xample.graph");

  cout << IF.is_open();
  IF.close();
  return 0;
}