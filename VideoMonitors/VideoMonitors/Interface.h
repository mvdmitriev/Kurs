#pragma once
#include <fstream>
#include <sstream>

class Interface
{
public:
	virtual void pprint() = 0;
	virtual void fprint(std::ofstream& f) = 0;
	virtual void pread() = 0;
	virtual void fread(std::stringstream& f, int i) = 0;
};