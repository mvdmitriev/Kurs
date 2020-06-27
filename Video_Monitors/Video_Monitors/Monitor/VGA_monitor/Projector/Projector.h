#pragma once
#include "..\VGA_monitor.h"
class Projector : public VGA_monitor
{
private:
	int min, max;

public:
	void pprint() override;
	void fprint(std::ofstream& f) override;
	void pread() override;
	void fread(std::stringstream& f, int i) override;

	Projector();
	Projector(int _id, int _width, int _height, char* _name, int _rate, int _min, int _max);
};