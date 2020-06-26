#include "stdafx.h"
#include "TV.h"
using namespace std;


void TV::pprint() {
	Monitor::pprint();
	cout << "����. ���������, ��: " << db << endl;
}

void TV::fprint(ofstream& f) {
	Monitor::fprint(f);
	f << " " << db;
}

void TV::pread() {
	Monitor::pread();
	cout << "����. ���������, ��: "; scanf("%d", &db);
	if (db < 0)
		throw "������: ������� ������������ ����. ���������\n";
}

void TV::fread(stringstream& f, int i) {
	Monitor::fread(f, i);
	f >> db;

	if (db < 0) {
		string ext = "� ������ �";
		ext += _itoa(i, new char[5], 10);
		ext += " ������� ������������ ����. ���������\n";
		throw ext;
	}
}

TV::TV() :Monitor()
{
	db = 0;
}

TV::TV(int _id, int _width, int _height, char* _name, int _db) :Monitor(_id, _width, _height, _name)
{
	db = _db;
}