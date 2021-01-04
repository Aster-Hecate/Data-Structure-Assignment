#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define HEADERS_READY

#include "lib/requisitories.h"
#include "lib/graph_class.cpp"
#include "lib/dijkstra.cpp"
#include "lib/menu.cpp"

using namespace std;

#define DEFAULT_FILE_NAME "example.graph"


int main() {
  //I LOVE UTF-8
  system("chcp 65001");
  system("cls");

  //1st trial of reading file
  ifstream file;
  cout << MENU_inputGraphFile;
  string fileName;
  getline(cin, fileName);
  if (fileName.size()) {
    file.open(fileName);
  }else{
    file.open(DEFAULT_FILE_NAME);
  }

  //2nd trial of reading file
  bool FLAG_fileValid = file.is_open();
  while (!FLAG_fileValid) {
    string fileNotValid = MENU_cannotFindGarphFile;
    fileNotValid.replace(fileNotValid.find("*"), 1, fileName);
    cout << fileNotValid;
    if (!(cin >> fileName)) {
      file.close();
      cout << MENU_farewell;
      return 0;
    }
  }

  // now the file is read.
  
  fileName = DEFAULT_FILE_NAME;
  string fileValid = MENU_loadedGraphFile;
  fileValid.replace(fileValid.find("*"), 1, fileName);
  cout << fileValid;
  // graph initialization
  Graph<double> G;
  G.init(file);

  // main menu
  string mainMenuInput;
  string verticleInput;
  cout << MENU_mainMenu;
  while(cin >> mainMenuInput) {
    if (mainMenuInput == "1") {
      bool FLAG_verticleValid = 0;
      cout << MENU_sourceForDijkstra;
      cin >> verticleInput;
      for (int i = 0; i < G.verticles.len; i++) {
        if (G.verticles[i] == verticleInput) {
          FLAG_verticleValid = 1;
          break;
        }
      }
      if (!FLAG_verticleValid) {
        string invalidVerticle = MENU_invalidVerticle;
        invalidVerticle.replace(invalidVerticle.find("*"), 1, verticleInput);
        cout << invalidVerticle;
        continue;
      }
      optimize(G, verticleInput);
    } else if (mainMenuInput == "2") {
      G.printMatrix();
    } else if (mainMenuInput == "3") {
      G.printVerticles();
    }
    system("pause");
    system("cls");
    cout << MENU_mainMenu;
  }
  file.close();
  cout << MENU_farewell;
  return 0;
}