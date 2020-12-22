#define THIS_IS_GRAPH_CLASS

#ifndef THIS_IS_REQUISITORIES
#include "requisitories.h"
#endif

#ifndef HEADERS_READY
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#define HEADERS_READY
#endif

#ifndef INFINITY
#define INFINITY 299792458
#endif

#define RIGHT_ARROW "->"
#define LEFT_ARROW "<-"
#define DOUBLE_ARROW "<->"

template <class DATA>
struct edge{
  std::string origin;
  std::string dest;
  DATA distance;
};

template <class DATA> class Graph {
public:
  DATA** adjacencyMatrix;
  List<std::string> verticles;
  List<edge<DATA> > edges;//each edge is directional
  //Graph();
  //~Graph();
  void init(std::ifstream&);
  void addVericleFromEdge(edge<DATA>);
};


template <class DATA>
void Graph<DATA>::addVericleFromEdge(edge<DATA> IHateNamingVariables) {
  if (verticles.search(IHateNamingVariables.origin) < 0) {
    verticles.append(IHateNamingVariables.origin);
  }
  if (verticles.search(IHateNamingVariables.dest) < 0) {
    verticles.append(IHateNamingVariables.dest);
  }
  //std::cout << "added verticles\n";
}

template <class DATA> void Graph<DATA>::init(std::ifstream &inputFromFile){
  std::cout << "\nINIT START\n";//TODO:
  
  int flagNonDirectional = 0;

  edge<DATA> temp[2];
  std::string str;
  std::string tempOrigin;
  std::string tempDest;
  int tempLength;

  std::string tempEdge[4];

  std::istringstream iss;


  //from file to verticles, edges
  while (!inputFromFile.eof()) {
    getline(inputFromFile, str);
    iss.str(str);
    for (int i = 0; iss >> tempEdge[i]; i++) ;
    iss.clear();
    //std::cout << "tempedge ready\n";
    if (tempEdge[1] == RIGHT_ARROW) {
      //std::cout << "case right\n";
      tempOrigin = tempEdge[0];
      tempDest = tempEdge[2];
      tempLength = std::stoi(tempEdge[3]);
      temp[0].origin = tempOrigin;
      temp[0].dest = tempDest;
      temp[0].distance = tempLength;
    } else if (tempEdge[1] == LEFT_ARROW) {
      //std::cout << "case left\n";
      tempOrigin = tempEdge[2];
      tempDest = tempEdge[0];
      tempLength = std::stoi(tempEdge[3]);
      temp[0].origin = tempOrigin;
      temp[0].dest = tempDest;
      temp[0].distance = tempLength;
    } else if (tempEdge[1] == DOUBLE_ARROW) {
      //std::cout << "case double\n";
      flagNonDirectional = 1;
      tempOrigin = tempEdge[0];
      tempDest = tempEdge[2];
      tempLength = std::stoi(tempEdge[3]);
      temp[0].origin = tempOrigin;
      temp[0].dest = tempDest;
      temp[0].distance = tempLength;
      temp[1].dest = tempOrigin;
      temp[1].origin = tempDest;
      temp[1].distance = tempLength;
    } else {
      //std::cout << "case empty\n";
      flagNonDirectional = 1;
      tempOrigin = tempEdge[0];
      tempDest = tempEdge[1];
      tempLength = std::stoi(tempEdge[2]);
      temp[0].origin = tempOrigin;
      temp[0].dest = tempDest;
      temp[0].distance = tempLength;
      temp[1].dest = tempOrigin;
      temp[1].origin = tempDest;
      temp[1].distance = tempLength;
    }

    //std::cout << "temp ready\n";
    
    //fill edges
    for(int i = 0; i < flagNonDirectional + 1; i++){
      edges.append(temp[i]);
    }

    //std::cout << "edges ready\n";

    //fill verticles
    addVericleFromEdge(temp[0]);
    // std::cout << "verticles ready\n";
    
    
  }

  
  
}