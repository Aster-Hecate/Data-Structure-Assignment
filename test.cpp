#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#define HEADERS_READY

#include "requisitories.h"
#include "graph_class.cpp"
#include "dijkstra.cpp"

using namespace std;

int main() {
	int select = 1;
	while (select != 0) {
		cout << "Menu" << endl;
		cout << "0、退出程序" << endl << "1、读入预定图文件并显示最短路径" << endl;
		cin >> select;
		switch (select) {
		case 0:
		{
			cout << "I can't believe!" << endl;
			return 0;
		}
		break;
		case 1: {
			string NAME;
			cout << "Name of the node" << endl;
			cin >> NAME;
			ifstream IF;
			IF.open("test");
			Graph<int> g;//创建一个空的图
			g.init(IF);//把打开的文件赋给g
			unitSet* us = optimize(g, "NAME");//unitSet是一个数组，里面存放着
			IF.close();
			delete us;
			system("pause"); system("cls");
			return 1;
			
		
		break;
		}
	}
	/*ifstream IF;
	IF.open("test");
	Graph<int> g;//创建一个空的图
	g.init(IF);//把打开的文件赋给g
	unitSet* us = optimize(g, "A");//unitSet是一个数组，里面存放着
	IF.close();
	delete us;*/


}
/*int showMenu() {
	int select;
	
	cout << "Menu" << endl;
	cout << "0、退出程序" << endl << "1、读入预定图文件" << endl << "2、显示最短路径" << endl;
	cin >> select;
	switch (select) {
	case 0:
	{
		cout << "I can't believe!" << endl;
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
*/