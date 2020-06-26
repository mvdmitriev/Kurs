#pragma once
#include "..\Monitor\HDMI_monitor\HDMI_monitor.h"
#include "..\Monitor\TV\Big_TV\Big_TV.h"
#include "..\Monitor\VGA_monitor\Projector\Projector.h"
using namespace std;

class Stack {
	//данные, скрытые от пользователя
private:
	struct Node {
		Monitor* data;
		Node* next;
	};
	Node* top;


	//методы для редактирования стэка
public:
	Stack();
	Stack(const Stack& paren);
	~Stack();
	void push(Monitor* value);
	bool empty() const;
	void pop();

	void download(string path);
	void upload(string path);

	//перегруженные операторы
	Stack& operator = (const Stack& paren);
	friend ostream& operator << (ostream& out, const Stack& stek)
	{
		if (!stek.empty())
		{
			stek.top->data->pprint();
			out << endl << endl;
		}
		else
			out << "Полка пуста" << endl << endl;
		return out;
	}
		

	//методы для обработки стэка

	void poisk_count(Monitor* monik); //поиск по габаритам
	void poisk_count(int _id);  //поиск по id
	void poisk_count(string namen); //поиск по типу

	void poisk_first(Monitor* monik);
	void poisk_first(int _id);
	void poisk_first(string namen);
};