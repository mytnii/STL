#include<iostream>
#include<array>
#include<vector>
#include<list>
#include<forward_list>

using std::cin;
using std::cout;
using std::endl;

#define delimiter cout << "\n------------------------------\n" << endl;

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
//#define STL_LIST
#define STL_FORWARD_LIST

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_ARRAY
	std::array<int, 5> arr = { 3,5,8,13,21 };

	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
#endif // STL_ARRAY
#ifdef STL_VECTOR
	std::vector<int> vec = { 0,1,1,2,3,5,8,13};
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << "\t";
	}
	cout << endl;
	cout << "Size:\t" << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	delimiter;

	//vec.shrink_to_fit();
	vec.reserve(25);
	//vec.resize(8);

	cout << "Size:\t" << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;

	try
	{
		for (int i = 0; i < vec.capacity(); ++i)
		{
			//cout << vec[i] << "\t";
			cout << vec.at(i) << "\t";
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;

	}
	cout << endl;

	cout << "Нулевой элемент вектора: " << vec.front() << endl;
	cout << "последний элемент вектора: " << vec.back() << endl;

	vec.assign({ 1,2,4,8,16,32 });
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;

	for (int i : vec)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "Size:\t" << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: ";
	cin >> index;

	cout << "Введите значение добавляемого элемента: ";
	cin >> value;

	//std::vector<int>::const_iterator position = vec.begin() + index;

	vec.insert(vec.begin() + index, value);

	for (int i : vec)
	{
		cout << i << "\t";
	}
	cout << endl;

#endif // STL_VECTOR

#ifdef STL_DEQUE
	//deque (double ended queue - двунаправленная очередь)
#endif // STL_DEQUE

#ifdef STL_LIST
	std::list<int> list = { 3,5,8,13,21 };

	for (int i : list)
	{
		cout << i << "\t";
	}
	cout << endl;

	int index;
	int value;

	cout << "Введите индекс добавляемого элемента: ";
	cin >> index;

	cout << "Введите значение добавляемого элемента: ";
	cin >> value;

	std::list<int>::iterator it = list.begin();

	/*for (int i = 0; i < index; ++i)
	{
		++it;
	}*/

	if (index <= list.size() )
	{
		std::advance(it, index);
		list.insert(it, value);
	}
	else
	{
		cout << "Выход за пределы списка\n";
	}

	/*list.insert(it, value);*/

	for (int i : list)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif // STL_LIST

#ifdef STL_FORWARD_LIST
	std::forward_list<int> list = { 3,5,8,13,21 };

	for (int i : list)
	{
		cout << i << "\t";
	}
	cout << endl;

	int index;
	int value;

	cout << "Введите индекс добавляемого элемента: ";
	cin >> index;

	cout << "Введите значение добавляемого элемента: ";
	cin >> value;

	std::forward_list<int>::iterator it = list.before_begin();

	if (index <= list.max_size())
	{
		std::advance(it, index);
		list.insert_after(it, value);
	}
	else
	{
		cout << "Выход за пределы списка\n";
	}

	for (int i : list)
	{
		cout << i << "\t";
	}
	cout << endl;


#endif // STL_


}