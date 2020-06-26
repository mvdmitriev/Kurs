#include "stdafx.h"
#include "Monitor.h"
using namespace std;


void Monitor::pprint() {
	cout << "ID: " << id << endl
		<< "Разрешение: " << width << "x" << height << endl;
	printf("Название: %s\n", name);
}

void Monitor::fprint(ofstream& f) {
	string type = typeid(*this).name();
	f << endl << type.erase(0, 6) << " "
		<< id << " "
		<< width << " " << height << " "
		<< name;
}

void Monitor::pread() {
	cout << "ID: "; scanf("%d", &id);
	if (id < 0)
		throw "Ошибка: введён неверный id\n";

	cout << "Ширина экрана: "; scanf("%d", &width);
	if (width < 0)
		throw "Ошибка: введена некорректная ширина\n";

	cout << "Высота экрана: "; scanf("%d", &height);
	if (height < 0)
		throw "Ошибка: введена некорректная высота\n";

	cout << "Название: "; cin.get(); cin.getline(name, 50);
	if (name[0] == 0)
		throw "Ошибка: введено пустое название\n";
}

void Monitor::fread(stringstream& f, int i) {
	f >> id >> width >> height >> name;

	if (id < 0) {
		string ext = "В записи №";
		ext += _itoa(i, new char[5], 10);
		ext += " указан некорректный id\n";
		throw ext;
	}
	if (width < 0) {
		string ext = "В записи №";
		ext += _itoa(i, new char[5], 10);
		ext += " указана некорректная ширина\n";
		throw ext;
	}
	if (height < 0) {
		string ext = "В записи №";
		ext += _itoa(i, new char[5], 10);
		ext += " указана некорректная высота\n";
		throw ext;
	}
	if (name[0] == 0) {
		string ext = "В записи №";
		ext += _itoa(i, new char[5], 10);
		ext += " не указано наименование\n";
		throw ext;
	}
}


Monitor::Monitor()
{
	id = 0;
	width = 0;
	height = 0;
}

Monitor::Monitor(int _id, int _width, int _height, char* _name)
{
	id = _id;
	width = _width;
	height = _height;
	name = _name;
}

bool Monitor::operator== (const Monitor & monik2)
{
	return (height == monik2.height && width == monik2.width);
}

bool Monitor::operator== (const int & _id)
{
	return (id == _id);
}