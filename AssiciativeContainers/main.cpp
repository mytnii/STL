#include<iostream>
#include<set>
#include<map>
#include<list>

using std::cin;
using std::cout;
using std::endl;

//#define STL_SET
//#define STL_MAP

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_SET
	std::set<int> myset = { 50, 25 ,75,16,32,64,80 };

	/*for (int i = 0; i < myset.size(); ++i)
	{
		cout << myset[i] << "\t";
	}
	cout << endl;*/

	for (int i : myset)
	{
		cout << i << "\t";
	}
	cout << endl;

	int value;

	cout << "Введите значение добавляемого элемента: ";
	cin >> value;

	myset.insert(value);

	for (int i : myset)
	{
		cout << i << "\t";
	}
	cout << endl;

	cout << "Введите значение удаляемого элемента: ";
	cin >> value;

	myset.erase(value);

	for (int i : myset)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (std::set<int>::iterator it = myset.lower_bound(25); it != myset.upper_bound(75); ++it)
	{
		cout << *it << "\t";
	}
	cout << endl;
	for (std::set<int>::iterator it = myset.find(25); it != myset.find(75); ++it)
	{
		cout << *it << "\t";
	}
	cout << endl;
#endif // STL_SET

#ifdef STL_MAP
	std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0,"Sunday"),
		std::pair<int, std::string>(1,"Monday"),
		std::pair<int, std::string>(2,"Tuesday"),
		std::pair<int, std::string>(3,"Wednsdey"),
		std::pair<int, std::string>(4,"Thursday"),
		std::pair<int, std::string>(5,"Friday"),
		std::pair<int, std::string>(6,"Saturday"),
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}
#endif // STL

	std::map<std::string, std::list<std::string>> dictionary
	{
		std::pair<std::string, std::list<std::string>>("splice", {"сваривание", "сращивание", "свадьба",}),
		{"reconnaissance", {"разведка", "зондирование"}},
		{"space", {"космос", "пространство", "пробел"}},
		{"pencil", {"карандаш"}},
		{"desk", {"рабочий стол", "доска"}},
		{"prohibit",{"запрещать"}},
		{"appreciate", {"быть презнательным", "ценит", "быть благодарным"}}
	};

	/*for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout << it->first << ":\t";
		for (std::list<std::string>::iterator l_it = it->second.begin(); l_it != it->second.end(); ++l_it)
		{
			cout << *l_it << ",";
		}
		cout << "\b;\n";
	}*/

	for (std::pair<std::string, std::list<std::string>>i : dictionary)
	{
		
		cout << i.first + "\t";
		for (std::string j : i.second)
		{
			cout << j << "\t";
		}
		cout << "\b\b;\n";
	}
}