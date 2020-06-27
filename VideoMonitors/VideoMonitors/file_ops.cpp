#include "stdafx.h"
#include "file_ops.h"


void download(string path, Stack& moniks) {
	ifstream f(path);
	if (f)
	{
		int i = 1;
		string line;
		while (!f.eof())
		{
			Monitor* monik;
			int id, width, height;
			char* name = new char[50];

			getline(f, line);
			stringstream ss;
			ss << line;
			ss >> name;

			if ((string)name == "VGA_monitor")
				monik = new VGA_monitor;
			else if ((string)name == "HDMI_monitor")
				monik = new HDMI_monitor;
			else if ((string)name == "TV")
				monik = new TV;
			else if ((string)name == "Projector")
				monik = new Projector;
			else if ((string)name == "Big_TV")
				monik = new Big_TV;
			else
			{
				string ext = "В записи №";
				ext += _itoa(i, new char[5], 10);
				ext += " указан некорректный тип\n";
				throw ext;
			}
			monik->fread(ss, i);
			moniks.push(monik);
			i++;
		}
	}
	else
		throw "Ошибка. Файл не найден или повреждён\n";
	f.close();
}

void upload(string path, Stack moniks) {
	ofstream f(path);
	Stack tmp = moniks;
	while (!tmp.empty())
	{
		f << tmp;
		tmp.pop();
	}
	f.close();
}