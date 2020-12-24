#include <limits>
#include <ostream>
#define THIS_IS_DIJKSTRA

#ifndef THIS_IS_REQUISITORIES
#include "../lib/requisitories.h"
#endif

#ifndef THIS_IS_GRAPH_CLASS
#include "../lib/graph_class.cpp"
#endif

#ifndef HEADERS_READY
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#endif

struct unitSet {
  int node;
  int length;
  int* path;
  int pathLength = 0;
};

template <class DATA> unitSet *optimize(Graph<DATA> G, std::string source) {
  int vlen = G.verticles.len;
  int iSource = G.verticles.search(source);
  unitSet *operate = new unitSet[vlen];
  unitSet *result = new unitSet[vlen];
for(int i = 0; i <= vlen; i++){
  operate[i].path = new int[vlen];
  result[i].path = new int[vlen];
}

  
  for (int i = 0; i < vlen; i++) {
    result[i].node = i;
    result[i].length = INFINITY;
    result[i].path[result[i].pathLength] = iSource;
    result[i].pathLength++;
    operate[i].node = i;
    operate[i].length = INFINITY;
    operate[i].path[operate[i].pathLength] = iSource;
    operate[i].pathLength++;
  }

  operate[iSource].length = 0;

  int shortestPathInOperate;
  int shortestPathLengthInOperate = INFINITY;
  int* vectorInOperate = new int(vlen);



  for (int round = 0; round < vlen; round++) {
    std::cout << "\nROUND " << round + 1 << "\n";
    //find vector
    for (int i = 0; i < vlen; i++) {
      if ((operate[i].length >= 0) &&
          (operate[i].length < shortestPathLengthInOperate)) {
        shortestPathInOperate = i;
        shortestPathLengthInOperate = operate[i].length;
      }
    }

    for(int i = 0; i < vlen; i++){
      vectorInOperate[i] = G.adjacencyMatrix[shortestPathInOperate][i];
    }

    //update result
    result[shortestPathInOperate].length =
        operate[shortestPathInOperate].length;
    /*
    for(int j = 0; j < operate[shortestPathInOperate].pathLength; j++){
      result[shortestPathInOperate].path[j] =
      operate[shortestPathInOperate].path[j];
    }
    result[shortestPathInOperate].pathLength =
    operate[shortestPathLengthInOperate].pathLength;
*/
    operate[shortestPathInOperate].length = -1;

    //update operate
    for (int i = 0; i < vlen; i++) {
      if ((shortestPathLengthInOperate + vectorInOperate[i]) <
          operate[i].length) {
        operate[i].length = (shortestPathLengthInOperate + vectorInOperate[i]);
        for(int j = 0; j < operate[shortestPathInOperate].pathLength; j++){
          operate[i].path[j] = operate[shortestPathInOperate].path[j];
        }
        operate[i].pathLength = operate[shortestPathInOperate].pathLength;
        operate[i].path[operate[i].pathLength] = i;
        operate[i].pathLength++;
      }
    }

    shortestPathLengthInOperate = INFINITY;

    std::cout << "VECTOR:\n";
    std::cout << G.verticles[shortestPathInOperate] << "\t";
    for (int i = 0; i < vlen; i++) {
      std::cout << vectorInOperate[i] << " ";
    }
    std::cout << "\n";

    
    std::cout << "OPERATE:\n";
    for (int i = 0; i < vlen; i++) {
      std::cout << G.verticles[operate[i].node] << " " << operate[i].length << " ";
      for (int j = 0; j < operate[i].pathLength; j++) {
        std::cout << G.verticles[operate[i].path[j]];
        }
      std::cout << "\n";
    }
  }

  for (int i = 0; i < vlen; i++) {
    for (int j = 0; j < operate[i].pathLength; j++) {
      result[i].path[j] = operate[i].path[j];
    }
    result[i].pathLength = operate[i].pathLength;
  }

   std::cout << "\nRESULT:\n";
    for (int i = 0; i < vlen; i++) {
      std::cout << G.verticles[result[i].node] << " " << result[i].length << " ";
      for (int j = 0; j < result[i].pathLength; j++) {
        std::cout << G.verticles[result[i].path[j]] ;
      }
      std::cout << "\n";
    }
  
  delete vectorInOperate;
  for(int i = 0; i <= vlen; i++){
    delete operate[i].path;
    delete result[i].path;
  }
  delete[] operate;
  return result;
}