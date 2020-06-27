#pragma once
#include "..\Monitor\Monitor.h"
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

	friend ofstream& operator << (ofstream& out, const Stack& stek)
	{
		if (!stek.empty())
		{
			stek.top->data->fprint(out);
			out << endl;
		}
		return out;
	}
		

	//методы для обработки стэка

	void poisk_count(Monitor* monik);	//подсчёт по габаритам
	void poisk_count(int _id);  		//подсчёт по id
	void poisk_count(string namen);		//подсчёт по типу

	void poisk_first(Monitor* monik);	//поиск первого подходящего по габаритам
	void poisk_first(int _id);		//по id
	void poisk_first(string namen);		//по типу
};