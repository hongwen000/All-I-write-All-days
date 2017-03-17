#pragma once
//
//  List.cpp
//  List
//
//  Created by scandy_yuan on 13-1-6.
//  Copyright (c) 2013�� Sam. All rights reserved.
//


class List {
public:
	List() { create_List(); }
	~List() { clear(); }
	//����ͷ���
	void create_List();
	//���뺯��
	void insert(const int& d);
	//��ָ��λ�ò���
	void insert_pos(const int& d, const int& d1);
	//ɾ��ָ�����ݵĽڵ�
	void erase(const int& d);
	//�޸�ָ������
	void updata(const int& d, const int& d1);
	//��ת������
	void reverse();
	//��ӡ
	void print();
	//�ڵ�ṹ
	struct Node {
		int data;
		Node * next;
		Node(const int& d) :data(d), next(NULL) {}
	};
	Node * head;//ͷ�ڵ�
				//����������
	void clear() {
		Node * p = head;
		//��ͷ�ڵ㿪ʼѭ��ɾ��
		while (p) {
			Node * q = p->next;
			delete p;
			p = q;
		}
	}
	//��������d����һ���ڵ�λ�õĺ���
	//Ϊ�˷������ɾ������
	Node* find(const int& d) {
		Node * p = head;
		for (; p; p = p->next) {
			if (p->next->data == d)
				break;
		}
		return p;
	}
};
Node* find(Node * temp) {
	Node * p = head;
	for (; p; p = p->next) {
		if (p == temp)
			break;
	}
	return p;
}
}
//����ͷ���
void List::create_List()
{
	head = new Node(0);
}
//��ͷ����һ���ڵ�
void List::insert(const int& d)
{
	Node *p = new Node(d);
	p->next = head->next;
	head->next = p;
}
//��ӡ����
void List::print()
{
	for (Node * p = head->next; p; p = p->next) {
		cout << p->data << endl;
	}
}
//��dλ��֮ǰ����d1
void List::insert_pos(const int& d, const int& d1)
{
	Node * p = find(d);
	Node * q = new Node(d1);
	q->next = p->next;
	p->next = q;
}

//ɾ��
void List::erase(const int& d)
{
	Node * p = find(d);
	//��Ϊp����һ���ڵ��λ�ã���q������
	//Ҫɾ���Ľڵ�ĵ�ַ
	Node *q = p->next;
	//ͨ������һ���ڵ��nextָ��ָ��Ҫɾ���ڵ��nextָ
	//��־��Ľڵ�ʵ�ֶϿ�Ҫɾ���ڵ��Ŀ��
	p->next = p->next->next;
	//ɾ��Ҫɾ���Ľڵ�q
	delete q;
}
void List::erase(Node * d)
{
	Node * p = find(d);
	//��Ϊp����һ���ڵ��λ�ã���q������
	//Ҫɾ���Ľڵ�ĵ�ַ
	Node *q = p->next;
	//ͨ������һ���ڵ��nextָ��ָ��Ҫɾ���ڵ��nextָ
	//��־��Ľڵ�ʵ�ֶϿ�Ҫɾ���ڵ��Ŀ��
	p->next = p->next->next;
	//ɾ��Ҫɾ���Ľڵ�q
	delete q;
}

//�޸�ָ������
void List::updata(const int& d, const int& d1)
{
	Node * p = find(d);
	p->next->data = d1;
}

//��ת����
void List::reverse()
{
	Node * p = head->next;//ͷ���֮��ĵ�1���ڵ�
	Node * q = head->next->next;//ͷ���֮��ĵ�2�ڵ�
	Node * m = head->next->next->next;//ͷ���֮��ĵ�3���ڵ�
	p->next = NULL;//��ͷ�ӵ�֮��ĵ�1���ڵ��nextָ����Ϊ��
				   //����m�Ƿ�Ϊ�����ж� �Դ�����ÿһ���ڵ�
	while (m) {
		q->next = p;
		p = q;
		q = m;
		m = m->next;
	}
	//�����һ���ڵ�����
	q->next = p;
	//��ͷ����ָ���µĵĵ�1���ڵ�(֮ǰ�����һ���ڵ�)
	head->next = q;
}
