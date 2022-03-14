#include<iostream>
#include<string>
#include<map>
#include<list>
#include<Windows.h>
#include<fstream>

#include"Crime.h"

using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n-------------------------------------------\n"

void print(const std::map<std::string, std::list<Crime>>& base);
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
			{"a777km", {Crime(1, "улица Ћенина"), Crime(2, "улю ‘рунзе")}},
			{"a557ab", {Crime(5, "ул.  осмонавтов")}},
			{"a001a", {Crime(4, "перекресток Ћенина и ќкт€брьской"), Crime(3, "ул. ќкт€брьска€")}}
		}*/;
	load(base, "base.txt");
	print(base);

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
		cout << delimiter;
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
			if (crimes.find(',') != std::string::npos)
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
			}
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

	cout << "¬ведите номер автомобил€: ";
	cin >> licence_plate;
	cout << "¬ведите правонарушение (номер статьи): ";
	cin >> id;
	cout << "¬ведите улицу где произошло правонарушение: ";
	cin >> place;
	cin.clear();
	cin.ignore();
	std::getline(cin, place);
	base[licence_plate].push_back(Crime(id, place));
}