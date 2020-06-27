#include "stdafx.h"
#include "HDMI_monitor.h"
using namespace std;


void HDMI_monitor::pprint() {
	VGA_monitor::pprint();
	cout << "Макс. громкость, дб: " << db << endl;
}

void HDMI_monitor::fprint(ofstream& f) {
	VGA_monitor::fprint(f);
	f << " " << db;
}

void HDMI_monitor::pread() {
	VGA_monitor::pread();
	cout << "Макс. громкость, дб: "; scanf("%d", &db);
	if (db < 0)
		throw "Ошибка: введена некорректная макс. громкость\n";
}

void HDMI_monitor::fread(stringstream& f, int i) {
	VGA_monitor::fread(f, i);
	f >> db;

	if (db < 0) {
		string ext = "В записи №";
		ext += _itoa(i, new char[5], 10);
		ext += " указана некорректная макс. громкость\n";
		throw ext;
	}
}

HDMI_monitor::HDMI_monitor() :VGA_monitor(), TV() {};

HDMI_monitor::HDMI_monitor(int _id, int _width, int _height, char* _name, int _rate, int _db) : Monitor(_id, _width, _height, _name), VGA_monitor(_id, _width, _height, _name, _rate), TV(_id, _width, _height, _name, _db) {};