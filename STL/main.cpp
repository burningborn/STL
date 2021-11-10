//  1)vector: ��������� ����������, ����� ��������� ������� ��� � �������� � �������������� ������ at

//  2)list: ���������� ������ �� �����, ����� ��������� ������ ����� �������� 
// (�� �������, ������������� ����� ������������ foreach), �������� ������������� ��������� �� ������, 
// ������ ����������� ������ ������� � ����.

//  3)map: ������������ ����� � ������� ���� string � ���������� ���� int, ��������� � ����� ��������� 
//������ ����� ��������� (��������� ����� ������� � ���������� ���� ���������� � �������� ���������� 
//��������� ������)

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <cstdlib>
using namespace std;

//#define VECTOR
#define LIST
//#define MAP

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

#ifdef VECTOR
	vector<int> testVector(10);
	for (int i = 0; i < 10; i++) {
		testVector.at(i) = rand() % 50;
	}
	for (int i = 0; i < 10; i++) {
		cout << testVector.at(i) << " ";
	}
	cout << endl;
#endif // VECTOR


#ifdef LIST
	list<int> testList;
	cout << "���������� ��������� ����� � ����: " << endl;
	ofstream out;
	out.open("list.txt");
	if (out.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			int temp = rand() % 10;
			out << temp << " ";
			cout << temp << " ";
		}
		cout << endl;
	}
	else
	{
		cout << " �������� ������� ����! " << endl;
	}
	out.close();

	cout << "���������� ����� �� ����� � ������  ��� ������ ������� push_back() \n� ������� �� ����� ��� ������ ����� for: " << endl;
	ifstream in;
	in.open("list.txt");
	if (in.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			int temp;
			in >> temp;
			cout << temp << " ";
			testList.push_back(temp);
		}
		cout << endl;
	}
	else
	{
		cout << " �������� ������� ����! " << endl;
	}
	in.close();

	cout << "����� ����������� ������ testList ��� ������ ���������: " << endl;
	for (auto iter = testList.begin(); iter != testList.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;

	cout << "�������� ������������� ��������� ������ \n� ����� �� �� ����� ��� ������ ����� range based: " << endl;
	testList.sort();										//��������� ������
	auto result = unique(begin(testList), end(testList));	//������� ������������� �������� � ����� ������
	testList.erase(result, testList.end());					//������� ������������� �������� �� ������
	for (int n : testList) cout << n << " ";				//������� ������ �� �����
	cout << endl;
#endif // LIST

#ifdef MAP
	map<string, int> myMap;
	string key, value;
	int code = 3;
	while (code)
	{
		cout << "������� �������� ����� (string): \n";
		getline(cin, key);
		cout << "������� �������� �������� (int): \n";
		getline(cin, value);
		int val = stoi(value);
		myMap.emplace(key, val);
		code--;
	}
	
	for (auto itMap = myMap.begin(); itMap != myMap.end(); itMap++)
	{
		cout << itMap->first << " * " << itMap->second << endl;
	}

#endif // MAP


}