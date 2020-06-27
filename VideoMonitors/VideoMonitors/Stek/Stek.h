#pragma once
#include "..\Monitor\Monitor.h"
using namespace std;

class Stack {
	//������, ������� �� ������������
private:
	struct Node {
		Monitor* data;
		Node* next;
	};
	Node* top;


	//������ ��� �������������� �����
public:
	Stack();
	Stack(const Stack& paren);
	~Stack();
	void push(Monitor* value);
	bool empty() const;
	void pop();


	//������������� ���������
	Stack& operator = (const Stack& paren);
	friend ostream& operator << (ostream& out, const Stack& stek)
	{
		if (!stek.empty())
		{
			stek.top->data->pprint();
			out << endl << endl;
		}
		else
			out << "����� �����" << endl << endl;
		return out;
	}

	friend ofstream& operator << (ofstream& out, const Stack& stek)
	{
		if (!stek.empty())
			stek.top->data->fprint(out);
		return out;
	}
		

	//������ ��� ��������� �����

	void poisk_count(Monitor* monik); //����� �� ���������
	void poisk_count(int _id);  //����� �� id
	void poisk_count(string namen); //����� �� ����

	void poisk_first(Monitor* monik);
	void poisk_first(int _id);
	void poisk_first(string namen);
};