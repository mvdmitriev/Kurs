#pragma once
#include <fstream>
#include <sstream>

class Interface
{
public:
	virtual void pprint() = 0;				//вывод на экран
	virtual void fprint(std::ofstream& f) = 0;		//вывод в файл
	virtual void pread() = 0;				//ввод с клавиатуры
	virtual void fread(std::stringstream& f, int i) = 0;	//ввод из файла
};