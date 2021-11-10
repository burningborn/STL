//  1)vector: рандомное заполнение, вывод элементов вектора как с массивом с использованием метода at

//  2)list: заполнение списка из файла, вывод элементов списка через итератор 
// (по желанию, дополнительно можно использовать foreach), удаление повторяющихся элементов из списка, 
// запись полученного списка обратно в файл.

//  3)map: формирование карты с ключами типа string и значениями типа int, сохранить в карту параметры 
//работы вашей программы (параметры можно вводить с клавиатуры либо передавать в качестве аргументов 
//командной строки)

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
	cout << "Записываем случайные числа в файл: " << endl;
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
		cout << " Неудаётся открыть файл! " << endl;
	}
	out.close();

	cout << "Записываем числа из файла в список  при помощи функции push_back() \nи выводим на экран при помощи цикла for: " << endl;
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
		cout << " Неудаётся открыть файл! " << endl;
	}
	in.close();

	cout << "Вывод содержимого списка testList при помощи итератора: " << endl;
	for (auto iter = testList.begin(); iter != testList.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;

	cout << "Удаление повторяющихся элементов списка \nи вывод их на экран при помощи цикла range based: " << endl;
	testList.sort();										//сортируем список
	auto result = unique(begin(testList), end(testList));	//выносим повторяющиеся элементы в конец списка
	testList.erase(result, testList.end());					//удаляем повторяющиеся элементы из списка
	for (int n : testList) cout << n << " ";				//выводим список на экран
	cout << endl;
#endif // LIST

#ifdef MAP
	map<string, int> myMap;
	string key, value;
	int code = 3;
	while (code)
	{
		cout << "Введите значение ключа (string): \n";
		getline(cin, key);
		cout << "Введите значение элемента (int): \n";
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