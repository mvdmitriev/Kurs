#pragma once
#include <string>
#include <iostream>
#include "..\Interface.h"

class Monitor : public Interface
{
protected:
	int id, width, height;
	char* name = new char[50];
	
public:
	void pprint();
	void fprint(std::ofstream& f);
	void pread();
	void fread(std::stringstream& f, int i);

	Monitor();
	Monitor(int _id, int _width, int _height, char* _name);

	bool operator== (const Monitor & monik2);
	bool operator== (const int & monik2);
};