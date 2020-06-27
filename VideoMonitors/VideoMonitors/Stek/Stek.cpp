#include "stdafx.h"
#include "Stek.h"


Stack::Stack()
{
	this->top = NULL;
}

Stack::Stack(const Stack& paren)
{
	this->top = paren.top;
}

Stack::~Stack()
{
	top = NULL;
}

void Stack::push(Monitor* value) {
	Node* tmp = new Node;
	tmp->next = top;
	top = tmp;
	top->data = value;
}

bool Stack::empty() const {
	return top == NULL;
}

void Stack::pop() {
	if (!empty())
	{
		Node *tmp = top;
		top = top->next;
		delete(tmp);
	}
	else
		cout << "Полка пуста" << endl << endl;
}


//перегруженные операторы
Stack& Stack::operator = (const Stack& paren)
{
	this->~Stack();
	this->top = paren.top;
	return *this;
}


//методы для обработки стэка

void Stack::poisk_count(Monitor* monik) //поиск по габаритам
{
	int i = 0;
	Node* tmp = top;
	while (tmp)
	{
		if (*tmp->data == *monik)
			i++;

		tmp = tmp->next;
	}
	if (i) cout << "Найдено мониторов: " << i << endl;
	else cout << "Мониторов не найдено" << endl;
}

void Stack::poisk_count(int _id)  //поиск по id
{
	int i = 0;
	Node* tmp = top;
	while (tmp)
	{
		if (*tmp->data == _id)
			i++;

		tmp = tmp->next;
	}
	if (i) cout << "Найдено мониторов: " << i << endl;
	else cout << "Мониторов не найдено" << endl;
}

void Stack::poisk_count(string namen) //поиск по типу
{
	int i = 0;
	Node* tmp = top;
	while (tmp)
	{
		if (typeid(*tmp->data).name() == namen)
			i++;

		tmp = tmp->next;
	}
	if (i) cout << "Найдено мониторов: " << i << endl;
	else cout << "Мониторов не найдено" << endl;
}

void Stack::poisk_first(Monitor* monik)
{
	int i = 1;
	Node* tmp = top;
	bool fl = false;
	while (tmp && !fl)
	{
		if (*tmp->data == *monik)
		{
			fl = true;
			break;
		}
		else
		{
			i++;
			tmp = tmp->next;
		}
	}
	if (fl) cout << "Ближайший монитор на " << i << " позиции на полке" << endl;
	else cout << "Данного монитора на полке нет" << endl;
}

void Stack::poisk_first(int _id)
{
	int i = 1;
	Node* tmp = top;
	bool fl = false;
	while (tmp)
	{
		if (*tmp->data == _id)
		{
			fl = true;
			break;
		}
		else
		{
			i++;
			tmp = tmp->next;
		}
	}
	if (fl) cout << "Ближайший монитор на " << i << " позиции на полке" << endl;
	else cout << "Данного монитора на полке нет" << endl;
}

void Stack::poisk_first(string namen)
{
	int i = 1;
	Node* tmp = top;
	bool fl = false;
	while (tmp)
	{
		if (typeid(*tmp->data).name() == namen)
		{
			fl = true;
			break;
		}
		else
		{
			i++;
			tmp = tmp->next;
		}
	}
	if (fl) cout << "Ближайший монитор на " << i << " позиции на полке" << endl;
	else cout << "Данного монитора на полке нет" << endl;
}