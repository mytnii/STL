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
void save_to_file(const std::map<std::string, std::list<Crime>>& base);


void main()
{
	/*setlocale(LC_ALL, "");*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::map<std::string, std::list<Crime>> base =
	{
		{"a777km", {Crime(1, "����� ������"), Crime(2, "��� ������")}},
		{"a557ab", {Crime(5, "��. �����������")}},
		{"a001a", {Crime(4, "����������� ������ � �����������"), Crime(3, "��. �����������")}}
	};

	print(base);

	std::string licence_plate;
	int id;
	std::string place;
	
	cout << "������� ����� ����������: ";
	cin >> licence_plate;
	cout << "������� �������������� (����� ������): ";
	cin >> id;
	cout << "������� ����� ��� ��������� ��������������: ";
	cin >> place;
	cin.clear();
	cin.ignore();
	std::getline(cin, place);
	base[licence_plate].push_back(Crime(id, place));
	print(base);

	save_to_file(base);
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

void save_to_file(const std::map<std::string, std::list<Crime>>& base)
{
	std::ofstream fout("base.txt");

	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		fout.width(10);
		fout << std::left;
		fout << it->first + ":";
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			fout << *jt << ", ";
		}
		fout << ";";
		fout << delimiter;
	}
	fout.close();
	system("notepad base.txt");
}