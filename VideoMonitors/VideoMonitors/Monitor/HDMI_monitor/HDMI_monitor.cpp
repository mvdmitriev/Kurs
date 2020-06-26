#include "stdafx.h"
#include "HDMI_monitor.h"
using namespace std;


void HDMI_monitor::pprint() {
	VGA_monitor::pprint();
	cout << "����. ���������, ��: " << db << endl;
}

void HDMI_monitor::fprint(ofstream& f) {
	VGA_monitor::fprint(f);
	f << " " << db;
}

void HDMI_monitor::pread() {
	VGA_monitor::pread();
	cout << "����. ���������, ��: "; scanf("%d", &db);
	if (db < 0)
		throw "������: ������� ������������ ����. ���������\n";
}

void HDMI_monitor::fread(stringstream& f, int i) {
	VGA_monitor::fread(f, i);
	f >> db;

	if (db < 0) {
		string ext = "� ������ �";
		ext += _itoa(i, new char[5], 10);
		ext += " ������� ������������ ����. ���������\n";
		throw ext;
	}
}

HDMI_monitor::HDMI_monitor() :VGA_monitor(), TV() {};

HDMI_monitor::HDMI_monitor(int _id, int _width, int _height, char* _name, int _rate, int _db) : Monitor(_id, _width, _height, _name), VGA_monitor(_id, _width, _height, _name, _rate), TV(_id, _width, _height, _name, _db) {};