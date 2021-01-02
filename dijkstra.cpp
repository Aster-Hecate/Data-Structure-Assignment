#include <limits>
#include <ostream>
#define THIS_IS_DIJKSTRA

#ifndef THIS_IS_REQUISITORIES
#include "requisitories.h"
#endif

#ifndef THIS_IS_GRAPH_CLASS
#include "graph_class.cpp"
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
	List<int> path;
};

template <class DATA> unitSet* optimize(Graph<DATA> G, std::string source) {
	int vlen = G.verticles.len;
	int iSource = G.verticles.search(source);
	unitSet* operate = new unitSet[vlen];
	unitSet* result = new unitSet[vlen];

	for (int i = 0; i < vlen; i++) {
		result[i].node = i;
		result[i].length = INFINITY;
		result[i].path.append(iSource);
		operate[i].node = i;
		operate[i].length = INFINITY;
		operate[i].path.append(iSource);
		/*
		if (operate[i].length < INFINITY) {
		  operate[i].path.append(i);
		}
	*/
	}

	operate[iSource].length = 0;

	int shortestPathInOperate;
	int shortestPathLengthInOperate = INFINITY;
	int* vectorInOperate = new int(vlen);



	for (int round = 0; round < vlen; round++) {
		std::cout << "\nROUND " << round + 1 << "\n";
		for (int i = 0; i < vlen; i++) {
			if ((operate[i].length >= 0) &&
				(operate[i].length < shortestPathLengthInOperate)) {
				shortestPathInOperate = i;
				shortestPathLengthInOperate = operate[i].length;
			}
		}

		for (int i = 0; i < vlen; i++) {
			vectorInOperate[i] = G.adjacencyMatrix[shortestPathInOperate][i];
		}

		result[shortestPathInOperate].length =
			operate[shortestPathInOperate].length;
		result[shortestPathInOperate].path =
			operate[shortestPathInOperate].path;
		operate[shortestPathInOperate].length = -1;

		for (int i = 0; i < vlen; i++) {
			if ((shortestPathLengthInOperate + vectorInOperate[i]) <
				operate[i].length) {
				operate[i].length = (shortestPathLengthInOperate + vectorInOperate[i]);
				operate[i].path = operate[shortestPathInOperate].path;
				operate[i].path.append(i);
				std::cout << "UPDATED " << G.verticles[i] << "\n";
			}
		}

		shortestPathLengthInOperate = INFINITY;

		std::cout << "VECTOR:\n";
		std::cout << G.verticles[shortestPathInOperate] << "\t";
		for (int i = 0; i < vlen; i++) {
			std::cout << vectorInOperate[i] << " ";
		}
		std::cout << "\n";

		std::cout << "RESULT:\n";
		for (int i = 0; i < vlen; i++) {
			std::cout << G.verticles[result[i].node] << " " << result[i].length << " ";
			for (int j = 0; j < result[i].path.len; j++) {
				std::cout << G.verticles[result[i].path[j]];
			}
			std::cout << "\n";
		}
		std::cout << "OPERATE:\n";
		for (int i = 0; i < vlen; i++) {
			std::cout << G.verticles[operate[i].node] << " " << operate[i].length << " ";
			for (int j = 0; j < operate[i].path.len; j++) {
				std::cout << G.verticles[operate[i].path[j]];
			}
			std::cout << "\n";
		}

	}

	delete vectorInOperate;

	return result;
}
int showMenu() {
	int select;

	std::cout << "Menu" <<std:: endl;
	std::cout << "0、退出程序" << std::endl << "1、读入预定图文件" << std::endl << "2、显示最短路径" <<std:: endl;
	std::cin >> select;
	switch (select) {
	case 0:
	{
		std::cout << "I can't believe!" << std::endl;
		return 0;
	}
	break;
	case 1: {

		system("pause"); system("cls");
		return 1;
	}
			break;
	case 2:
	{
		system("pause"); system("cls");
		return 1;
	}
	break;
	}
}
