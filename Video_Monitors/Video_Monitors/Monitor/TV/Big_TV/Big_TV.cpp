#include "stdafx.h"
#include "Big_TV.h"
using namespace std;


void Big_TV::pprint() {
	TV::pprint();
	cout << "Объёмный звук (1 - есть, 0 - нет): " << (int)big_sound << endl;
}

void Big_TV::fprint(ofstream& f) {
	TV::fprint(f);
	f << " " << big_sound;
}

void Big_TV::pread() {
	TV::pread();
	cout << "Объёмный звук (1 - есть, 0 - нет): "; scanf("%d", &big_sound);
	if (db < 0)
		throw "Ошибка: введено некорректное значение наличия объёмного звука (должно быть 0 или 1)\n";
}

void Big_TV::fread(stringstream& f, int i) {
	TV::fread(f, i);
	f >> big_sound;

	if (big_sound < 0) {
		string ext = "В записи №";
		ext += _itoa(i, new char[5], 10);
		ext += " указано некорректное значение наличия объёмного звука\n";
		throw ext;
	}
}

Big_TV::Big_TV() :TV()
{
	big_sound = -1;
}

Big_TV::Big_TV(int _id, int _width, int _height, char* _name, int _db, bool _bs) :Monitor(_id, _width, _height, _name), TV(_id, _width, _height, _name, _db)
{
	big_sound = _bs;
}