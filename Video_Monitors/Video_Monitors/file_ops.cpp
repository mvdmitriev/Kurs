#include "stdafx.h"
#include "file_ops.h"

void download(string path, Stack& moniks) {
	ifstream f(path);
	if (f)
	{
		int i = 1;		//считываемая позиция
		string line;		//считываемый элемент
		while (!f.eof())
		{
			Monitor* monik;
			string name;

			getline(f, line);	//считывание элемента
			if (line != "")
			{
				stringstream ss;
				ss << line;
				ss >> name;	//считывание типа

				if (name == "VGA_monitor")
					monik = new VGA_monitor;
				else if (name == "HDMI_monitor")
					monik = new HDMI_monitor;
				else if (name == "TV")
					monik = new TV;
				else if (name == "Projector")
					monik = new Projector;
				else if (name == "Big_TV")
					monik = new Big_TV;
				else			//если указан неверный тип
				{
					string ext = "В записи №";
					ext += _itoa(i, new char[5], 10);
					ext += " указан некорректный тип\n";
					throw ext;
				}
				monik->fread(ss, i);	//считывание данных
				moniks.push(monik);	//добавление в стек
				i++;
			}
		}
		f.close();
	}
	else
	{
		throw "Ошибка. Файл не найден или повреждён\n";
	}
}

void upload(string path, Stack moniks) {
	ofstream f(path);
	Stack tmp = moniks;	//создание копии списка
	while (!tmp.empty())
	{
		f << tmp;
		tmp.pop();
	}
	f.close();
}