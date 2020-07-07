#pragma once
#include "..\Interface.h"
#include "iostream"
using namespace std;

class Stack {
	//данные, скрытые от пользователя
private:
	struct Node {
		//Monitor* data;
		Interface* data;
		Node* next;
	};
	Node* top;


	//методы для редактирования стэка
public:
	Stack();
	Stack(const Stack& paren);
	~Stack();
	void push(Interface* value);
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

	void poisk_count(Interface* monik); //поиск по габаритам
	void poisk_count(int _id);  //поиск по id
	void poisk_count(string namen); //поиск по типу

	void poisk_first(Interface* monik);
	void poisk_first(int _id);
	void poisk_first(string namen);
};