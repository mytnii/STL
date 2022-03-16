#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<map>
#include<list>
#include<Windows.h>
#include<fstream>
//#include<conio.h>

#include"Crime.h"

using std::cin;
using std::cout;
using std::endl;

void print(const std::map<std::string, std::list<Crime>>& base);
void print(const std::map<std::string, std::list<Crime>>& base, const std::string& licence_plate);
void print(const std::map<std::string, std::list<Crime>>& base, const std::string& first_plate, const std::string& last_plate);
void save_to_file(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);
void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename);
void add(std::map<std::string, std::list<Crime>>& base);




void main()
{
	/*setlocale(LC_ALL, "");*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::map<std::string, std::list<Crime>> base/*=
		{
			{"a777km", {Crime(1, "улица Ленина"), Crime(2, "улю Фрунзе")}},
			{"a557ab", {Crime(5, "ул. Космонавтов")}},
			{"a001a", {Crime(4, "перекресток Ленина и Октябрьской"), Crime(3, "ул. Октябрьская")}}
		}*/;
	load(base, "base.txt");
	load(base, "base.txt");
	load(base, "base.txt");
	print(base);

	/*std::string licence_plate;
	cout << "Введите номер транспортного средства: ";
	cin >> licence_plate;
	print(base, licence_plate);*/

	std::string first_plate, last_plate;
	cout << "Введите начальный номерной знак:";
	cin >> first_plate;
	cout << "Введите конечный номерной знак:";
	cin >> last_plate;
	print(base, first_plate, last_plate);

	/*add(base);
	
	print(base);*/

	//save_to_file(base, "base.txt");
}

void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first + ":\n";
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << "\t" << *jt << ";\n";
		}
		cout << "\n---------------------------------------------------------------------------\n";
	}

}

void print(const std::map<std::string, std::list<Crime>>& base, const std::string& licence_plate)
{
	try
	{
		cout << licence_plate << ":\n";
		for (std::list<Crime>::const_iterator it = base.at(licence_plate).begin();
			it != base.at(licence_plate).end(); ++it)
		{
			cout << *it << endl;
		}
	}
	catch (...)
	{
		std::cerr << "В базе нет такого номера" << endl;
	}
}

void print(const std::map<std::string, std::list<Crime>>& base, const std::string& first_plate, const std::string& last_plate)
{
	try
	{
		for (std::map<std::string, std::list<Crime>>::const_iterator it = base.lower_bound(first_plate);
			it != base.upper_bound(last_plate);
			++it
			)
		{
			cout << it->first << ":\n";
			for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{
				cout << *jt << endl;
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
}


void save_to_file(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename);

	for (std::pair<std::string, std::list<Crime>> i : base)
	{
		fout << i.first << ":\t";
		for (Crime j : i.second)
		{
			fout << j << ", ";
		}
		fout.seekp(-2, std::ios::cur);
		fout << ";\n";
	}
	fout.close();
	std::string command = std::string("start notepad ") + filename;
	system(command.c_str());
}

void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string licence_plate;
			int id;
			std::string place;
			std::string crimes;
			std::getline(fin, licence_plate, ':');
			std::getline(fin, crimes);
			if (crimes.empty())continue;
			/*if (crimes.find(',') != std::string::npos)
			{
				for (int start = 0, end = crimes.find(','); end != std::string::npos; start = end)
				{
					end = crimes.find(',', start + 1);
					place = crimes.substr(start + 1, end);
					place.erase(0, place.find_first_not_of(' '));
					id = std::stoi(place.substr(0, place.find_first_of(' ')));
					place.erase(0, place.find_first_of(' '));
					base[licence_plate].push_back(Crime(id, place));
				}
			}
			else
			{
				id = std::stoi(crimes.substr(0, crimes.find_first_of(' ')));
				crimes.erase(0, crimes.find_first_of(' '));
				base[licence_plate].push_back(Crime(id, place));
			}*/
			char* sz_crimes = new char[crimes.size() + 1]{};
			{

			};
			strcpy(sz_crimes, crimes.c_str());
			char delimiter[] = ",;";
			for (char* pch = strtok(sz_crimes, delimiter); pch; pch = strtok(NULL, delimiter))
			{
				while (*pch == ' ')pch++;
				id = std::atoi(pch);
				pch = std::strchr(pch, ' ') + 1;
				if (
					std::find(base[licence_plate].begin(), base.at(licence_plate).end(), Crime(id, pch))
					== base[licence_plate].end()
					)
				base[licence_plate].push_back(Crime(id, pch));
			}

			delete[] sz_crimes;

		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found:" << endl;
	}
}


void add(std::map<std::string, std::list<Crime>>& base)
{
	std::string licence_plate;
	int id;
	std::string place;

	cout << "Введите номер автомобиля: ";
	cin >> licence_plate;
	cout << "Введите правонарушение (номер статьи): ";
	cin >> id;
	cout << "Введите улицу где произошло правонарушение: ";
	cin >> place;
	cin.clear();
	cin.ignore();
	std::getline(cin, place);
	base[licence_plate].push_back(Crime(id, place));
}