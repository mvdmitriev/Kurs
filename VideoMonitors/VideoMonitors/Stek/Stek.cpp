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
		cout << "����� �����" << endl << endl;
}


void Stack::download(string path)
{
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
				monik = new Monitor;
			else if ((string)name == "HDMI_monitor")
				monik = new VGA_monitor;
			else if ((string)name == "TV")
				monik = new TV;
			else if ((string)name == "Projector")
				monik = new HDMI_monitor;
			else if ((string)name == "Big_TV")
				monik = new Big_TV;
			else
			{
				string ext = "� ������ �";
				ext += _itoa(i, new char[5], 10);
				ext += " ������ ������������ ���\n";
				throw ext;
			}
			monik->fread(ss, i);
			push(monik);
			i++;
		}
	}
	else
		throw "������. ���� �� ������ ��� ��������\n";
	f.close();
}

void Stack::upload(string path)
{
	ofstream f(path);
	Node* tmp = top;
	while (tmp)
	{
		tmp->data->fprint(f);
		tmp = tmp->next;
	}
	f.close();
}


//������������� ���������
Stack& Stack::operator = (const Stack& paren)
{
	this->~Stack();
	this->top = paren.top;
	return *this;
}


//������ ��� ��������� �����

void Stack::poisk_count(Monitor* monik) //����� �� ���������
{
	int i = 0;
	Node* tmp = top;
	while (tmp)
	{
		if (*tmp->data == *monik)
			i++;

		tmp = tmp->next;
	}
	if (i) cout << "������� ���������: " << i << endl;
	else cout << "��������� �� �������" << endl;
}

void Stack::poisk_count(int _id)  //����� �� id
{
	int i = 0;
	Node* tmp = top;
	while (tmp)
	{
		if (*tmp->data == _id)
			i++;

		tmp = tmp->next;
	}
	if (i) cout << "������� ���������: " << i << endl;
	else cout << "��������� �� �������" << endl;
}

void Stack::poisk_count(string namen) //����� �� ����
{
	int i = 0;
	Node* tmp = top;
	while (tmp)
	{
		if (typeid(*tmp->data).name() == namen)
			i++;

		tmp = tmp->next;
	}
	if (i) cout << "������� ���������: " << i << endl;
	else cout << "��������� �� �������" << endl;
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
	if (fl) cout << "��������� ������� �� " << i << " ������� �� �����" << endl;
	else cout << "������� �������� �� ����� ���" << endl;
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
	if (fl) cout << "��������� ������� �� " << i << " ������� �� �����" << endl;
	else cout << "������� �������� �� ����� ���" << endl;
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
	if (fl) cout << "��������� ������� �� " << i << " ������� �� �����" << endl;
	else cout << "������� �������� �� ����� ���" << endl;
}