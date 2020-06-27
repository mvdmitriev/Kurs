#pragma once
#include "..\Monitor.h"

class TV :virtual public Monitor
{
protected:
	int db;

public:
	void pprint();
	void fprint(std::ofstream& f);
	void pread();
	void fread(std::stringstream& f, int i);

	TV();
	TV(int _id, int _width, int _height, char* _name, int _db);
};