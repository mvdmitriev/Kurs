#include "stdafx.h"
#include "file_ops.h"


int main()
{
	setlocale(LC_ALL, "");

	Stack moniks;
	int doin = -1;

	printf("Загрузить данные из файла? (ввод 1, если да)\n");
	scanf("%d", &doin);

	if (doin == 1)
	{
		printf("\nВведите путь к файлу: ");
		string path;
		cin.get();
		getline(cin, path);
		try
		{
			download(path, moniks);
		}
		catch (string _wha)
		{
			cout << _wha;
		}
		catch (char* _wha)
		{
			printf("%s", _wha);
		}
	}

	doin = 1;

	while (doin > 0 && doin <= 6)
	{
		cout << "\nВыберите действие:" << endl
			<< "0 - выход" << endl
			<< "1 - положить устройство на полку" << endl
			<< "2 - снять устройство с полки" << endl
			<< "3 - поиск интересующего устройства" << endl
			<< "4 - подсчёт интересующих устройств" << endl
			<< "5 - просмотреть информацию о крайнем устройстве на полке" << endl
			<< "6 - убрать все устройства с полки" << endl << endl;
		scanf("%d", &doin);

		switch (doin)
		{
		case 1:
		{
			try
			{
				cout << "\nВыберите тип устройства: " << endl
					<< "1 - VGA-монитор" << endl
					<< "2 - HDMI-монитор" << endl
					<< "3 - Телевизор" << endl
					<< "4 - Проектор" << endl
					<< "5 - Домашний кинотеатр" << endl
					<< "0 - Отмена" << endl << endl;
				int chs;
				scanf("%d", &chs);
				while (!(chs >= 0 && chs <= 5))
				{
					cout << "Введите корректный номер" << endl;
					scanf("%d", &chs);
				}
				Monitor* monik;
				if (chs == 1)
					monik = new VGA_monitor;
				else if (chs == 2)
					monik = new HDMI_monitor;
				else if (chs == 3)
					monik = new TV;
				else if (chs == 4)
					monik = new Projector;
				else if (chs == 5)
					monik = new Big_TV;
				monik->pread();
				moniks.push(monik);
			}
			catch (char* _wha)
			{
				printf("\n%s\n", _wha);
			}
			break;
		}

		case 2:
			moniks.pop();
			cout << endl;
			break;

		case 3:
		{
			try
			{
				if (moniks.empty()) cout << "Полка пуста" << endl << endl;
				else
				{
					cout << "\nВыберите критерий: " << endl
						<< "1 - по id" << endl
						<< "2 - по типу" << endl
						<< "3 - по размеру" << endl
						<< "0 - Отмена" << endl << endl;
					int chs;
					scanf("%d", &chs);
					while (!(chs >= 0 && chs <= 3))
					{
						cout << "Введите корректный номер" << endl;
						scanf("%d", &chs);
					}
					if (chs == 1)
					{
						cout << "\nВведите id: ";
						int id;
						scanf("%d", &id);
						if (id < 0) throw "Ошибка: введён неверный id\n\n";
						moniks.poisk_first(id);
					}
					else if (chs == 2)
					{
						cout << "\nВыберите тип: " << endl
							<< "1 - VGA-монитор" << endl
							<< "2 - HDMI-монитор" << endl
							<< "3 - Телевизор" << endl
							<< "4 - Проектор" << endl
							<< "5 - Домашний кинотеатр" << endl
							<< "0 - Отмена" << endl << endl;
						int chs;
						scanf("%d", &chs);
						while (!(chs >= 0 && chs <= 5))
						{
							cout << "Введите корректный номер" << endl;
							scanf("%d", &chs);
						}
						if (chs == 1)
						{
							moniks.poisk_first("class VGA_Monitor");
						}
						else if (chs == 2)
						{
							moniks.poisk_first("class HDMI_monitor");
						}
						else if (chs == 3)
						{
							moniks.poisk_first("class TV");
						}
						else if (chs == 4)
						{
							moniks.poisk_first("class Projector");
						}
						else if (chs == 5)
						{
							moniks.poisk_first("class Big_TV");
						}
					}
					else if (chs == 3)
					{
						Monitor monik;
						monik.pread();
						moniks.poisk_first(&monik);
					}
				}
				system("pause");
				cout << endl;
			}
			catch (char* _wha)
			{
				printf("\n%s\n", _wha);
			}
			break;
		}

		case 4:
		{
			try
			{
				if (moniks.empty()) cout << "Полка пуста" << endl << endl;
				else
				{
					cout << "\nВыберите критерий: " << endl
						<< "1 - по id" << endl
						<< "2 - по типу" << endl
						<< "3 - по размеру" << endl
						<< "0 - Отмена" << endl << endl;
					int chs;
					scanf("%d", &chs);
					while (!(chs >= 0 && chs <= 3))
					{
						cout << "Введите корректный номер" << endl;
						scanf("%d", &chs);
					}
					if (chs == 0);
					else if (chs == 1)
					{
						cout << "\nВведите id: ";
						int id;
						scanf("%d", &id);
						if (id < 0) throw "Ошибка: введён неверный id\n\n";
						moniks.poisk_count(id);
					}
					else if (chs == 2)
					{
						cout << "\nВыберите тип: " << endl
							<< "1 - VGA-монитор" << endl
							<< "2 - HDMI-монитор" << endl
							<< "3 - Телевизор" << endl
							<< "4 - Проектор" << endl
							<< "5 - Домашний кинотеатр" << endl
							<< "0 - Отмена" << endl << endl;
						int chs;
						scanf("%d", &chs);
						while (!(chs >= 0 && chs <= 5))
						{
							cout << "Введите корректный номер" << endl;
							scanf("%d", &chs);
						}
						if (chs == 1)
						{
							moniks.poisk_count("class VGA_Monitor");
						}
						else if (chs == 2)
						{
							moniks.poisk_count("class HDMI_monitor");
						}
						else if (chs == 3)
						{
							moniks.poisk_count("class TV");
						}
						else if (chs == 4)
						{
							moniks.poisk_count("class Projector");
						}
						else if (chs == 5)
						{
							moniks.poisk_count("class Big_TV");
						}
					}
					else if (chs == 3)
					{
						Monitor monik;
						monik.pread();
						moniks.poisk_count(&monik);
					}
				}
				system("pause");
				cout << endl;
			}
			catch (char* _wha)
			{
				printf("\n%s\n", _wha);
			}
			break;
		}

		case 5:
			cout << moniks;
			system("pause");
			cout << endl;
			break;

		case 6:
			moniks.~Stack();
			break;
		}
	}

	printf("Выгрузить данные в файл? (ввод 1, если да)\n");
	scanf("%d", &doin);

	if (doin == 1)
	{
		printf("Введите путь к файлу: ");
		string path;
		cin.get();
		getline(cin, path);
		upload(path, moniks);
	}

	return 0;
}