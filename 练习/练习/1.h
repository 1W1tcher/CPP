#pragma once
#include<iostream>
#include<ctime>
using namespace std;

template<class T>
struct Node
{
	T data = 0;
	Node<T>* next;
	int cnt = 0;
};

template<class T>
class LinkList
{
public:

	void PrintList();

	Node<T>* Get(int i);

	Node<T>* front;
	int N = 0;
};

LinkList<int> MakeGreatInt()
{
	int N = rand() % 50 + 1;//生成1~50位
	LinkList<int> L1;//初始化链表
	L1.N = N;
	L1.front = new Node<int>;
	L1.front->next = NULL;
	Node<int>* s = new Node<int>;
	s->data = rand() % 9 + 1;//首位不能为0
	s->next = L1.front->next;
	L1.front->next = s;

	for (int i = 1;i < N;i++)//为每一数位生成随机数
	{
		Node<int>* s = new Node<int>;
		s->data = rand() % 10;
		s->next = L1.front->next;
		L1.front->next = s;
	}
	return L1;
}

template<class T>
void LinkList<T>::PrintList()
{
	int cnt = 0;
	Node<T>* p = front->next;
	while (p)
	{
		cout << p->data;
		p = p->next;
		cnt++;
	}
	cout << endl;
	cout << "整数的数位：" << cnt << endl;

}


template<class T>
class Solution
{
	Node<T>* ReverseList(Node<T>* list)
	{
		Node<T>* ptr1 = nullptr;
		Node<T>* ptr2 = list;
		while (ptr2!=nullptr)
		{
			Node<T>* temp = ptr2->next;
			ptr2->next = ptr1;
			ptr1 = ptr2;	
			ptr2 = temp;
		}
		
		return ptr1;
	}

public:
	Node<T>* AddTwoNumbers(Node<T>* l1, Node<T>* l2)
	{
		Node<T>* l1copy = ReverseList(l1);
		Node<T>* l2copy = ReverseList(l2);
		int jw = 0;
		int num1 = 0,num2 = 0;
		Node<T>* tmp = new Node<T>;
		Node<T>* ptr = tmp;
		while (l1copy != nullptr || l2copy != nullptr || jw)
		{
			if (l1copy != nullptr)
			{
				num1 = l1copy->data;
				l1copy = l1copy->next;
			}
			else
			{
				num1 = 0;
			}
			if (l2copy != nullptr)
			{
				num2 = l2copy->data;
				l2copy = l2copy->next;
			}
			else
			{
				num2 = 0;
			}
			int num = num1 + num2 + jw;
			jw = num / 10;
			num %= 10;
			ptr->next = new Node<T>;
			ptr->next->data = num;
			ptr = ptr->next;
		}
		ptr->next = NULL;
		return ReverseList(tmp->next);
	}

};