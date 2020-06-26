#include "stdafx.h"
#include "Projector.h"
using namespace std;


void Projector::pprint() {
	VGA_monitor::pprint();
	cout << "����������� ��������� �����������: " << min << endl;
	cout << "������������ ��������� �����������: " << max << endl;	
}

void Projector::fprint(ofstream& f) {
	VGA_monitor::fprint(f);
	f << " " << min << " " << max;
}

void Projector::pread() {
	VGA_monitor::pread();
	cout << "����������� ��������� �����������: "; scanf("%d", &min);
	if (min < 0)
		throw "������: ������� ������������ ���. ���������\n";

	cout << "������������ ��������� �����������: "; scanf("%d", &max);
	if (max < 0)
		throw "������: ������� ������������ ����. ���������\n";
}

void Projector::fread(stringstream& f, int i) {
	VGA_monitor::fread(f, i);
	f >> min >> max;

	if (min < 0) {
		string ext = "� ������ �";
		ext += _itoa(i, new char[5], 10);
		ext += " ������� ������������ ���. ���������\n";
		throw ext;
	}
	if (max < 0) {
		string ext = "� ������ �";
		ext += _itoa(i, new char[5], 10);
		ext += " ������� ����������� ����. ���������\n";
		throw ext;
	}
}

Projector::Projector() :VGA_monitor()
{
	min = max = 0;
}

Projector::Projector(int _id, int _width, int _height, char* _name, int _rate, int _min, int _max) : Monitor(_id, _width, _height, _name), VGA_monitor(_id, _width, _height, _name, _rate)
{
	min = _min;
	max = _max;
}