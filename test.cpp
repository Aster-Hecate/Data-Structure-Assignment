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
		cout << "0���˳�����" << endl << "1������Ԥ��ͼ�ļ�����ʾ���·��" << endl;
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
			Graph<int> g;//����һ���յ�ͼ
			g.init(IF);//�Ѵ򿪵��ļ�����g
			unitSet* us = optimize(g, "NAME");//unitSet��һ�����飬��������
			IF.close();
			delete us;
			system("pause"); system("cls");
			return 1;
			
		
		break;
		}
	}
	/*ifstream IF;
	IF.open("test");
	Graph<int> g;//����һ���յ�ͼ
	g.init(IF);//�Ѵ򿪵��ļ�����g
	unitSet* us = optimize(g, "A");//unitSet��һ�����飬��������
	IF.close();
	delete us;*/


}
/*int showMenu() {
	int select;
	
	cout << "Menu" << endl;
	cout << "0���˳�����" << endl << "1������Ԥ��ͼ�ļ�" << endl << "2����ʾ���·��" << endl;
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