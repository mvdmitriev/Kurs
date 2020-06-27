#include "stdafx.h"
#include "VGA_monitor.h"
using namespace std;


void VGA_monitor::pprint() {
	Monitor::pprint();
	cout << "Частота, Гц: " << Rate << endl;
}

void VGA_monitor::fprint(ofstream& f) {
	Monitor::fprint(f);
	f << " " << Rate;
}

void VGA_monitor::pread() {
	Monitor::pread();
	cout << "Частота, Гц: "; scanf("%d", &Rate);
	if (Rate < 0)
		throw "Ошибка: введена некорректная частота\n";
}

void VGA_monitor::fread(stringstream& f, int i) {
	Monitor::fread(f, i);
	f >> Rate;

	if (Rate < 0) {
		string ext = "В записи №";
		ext += _itoa(i, new char[5], 10);
		ext += " указана некорректная частота\n";
		throw ext;
	}
}

VGA_monitor::VGA_monitor() :Monitor()
{
	Rate = -1;
}

VGA_monitor::VGA_monitor(int _id, int _width, int _height, char* _name, int _rate) :Monitor(_id, _width, _height, _name)
{
	Rate = _rate;
}