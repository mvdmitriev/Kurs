#pragma once
#include "..\Monitor\HDMI_monitor\HDMI_monitor.h"
#include "..\Monitor\TV\Big_TV\Big_TV.h"
#include "..\Monitor\VGA_monitor\Projector\Projector.h"
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

	void download(string path);
	void upload(string path);

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
		

	//������ ��� ��������� �����

	void poisk_count(Monitor* monik); //����� �� ���������
	void poisk_count(int _id);  //����� �� id
	void poisk_count(string namen); //����� �� ����

	void poisk_first(Monitor* monik);
	void poisk_first(int _id);
	void poisk_first(string namen);
};