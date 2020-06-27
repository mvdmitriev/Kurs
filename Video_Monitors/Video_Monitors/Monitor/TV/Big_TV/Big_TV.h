#pragma once
#include "..\TV.h"

class Big_TV :public TV
{
private:
	bool big_sound;

public:
	void pprint() override;
	void fprint(std::ofstream& f) override;
	void pread() override;
	void fread(std::stringstream& f, int i) override;

	Big_TV();
	Big_TV(int _id, int _width, int _height, char* _name, int _db, bool _bs);
};