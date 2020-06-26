#pragma once
#include "..\Monitor.h"

class VGA_monitor : virtual public Monitor
{
protected:
	int Rate;

public:
	void pprint();
	void fprint(std::ofstream& f);
	void pread();
	void fread(std::stringstream& f, int i);

	VGA_monitor();
	VGA_monitor(int _id, int _width, int _height, char* _name, int _rate);
};