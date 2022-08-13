#pragma once
#include<iostream>
#include<stdio.h>
#include <malloc.h>
using namespace std;
const int MAXSIZE = 1000;

template<class T>
struct Node
{
	T data;
	Node<T>* next;
};

template<class T>
class LinkList
{
public:
	LinkList()
	{
		front = new Node<T>;
		front->next = NULL;
	}

	LinkList(const T a[],int n);

	~LinkList();

	int GetLength();

	void PrintList();

	void Insert(int i, T x);

	T Delete(int i);

	Node<T>* Get(int i);

	int Locate(T x);

	void Merge(LinkList<T> &a,LinkList<T> &b);

private:  
	Node<T>* front;
};

template<class T>
LinkList<T>::LinkList(const T a[], int n)
{
	//头插法
	//front = new Node<T>;
	//front->next = NULL;
	//for (int i = 0;i < n;i++)
	//{
	//	Node<T>* s = new Node<T>;
	//	s->data = a[i];
	//	s->next = front->next;
	//	front->next = s;
	//}
	
	//尾插法
	front = new Node<T>;
	Node<T>* r = front;
	for (int i = 0;i < n;i++)
	{
		Node<T>* s = new Node<T>;
		s->data = a[i];
		r -> next = s;
		r = s;
	}
	r->next = NULL;
}

template<class T>
LinkList<T>::~LinkList()
{
	Node<T>* p = NULL;
	while (front)
	{
		p = front;
		front = front->next;
		delete p;
	}
}

template<class T>
int LinkList<T>::GetLength()
{
	Node<T>* p = front->next;
	int i = 1;
	while (p)
	{
		p = p->next;
		i++;
	}
	return i;
}

template<class T>
void LinkList<T>::PrintList()
{
	cout << "按序号依次遍历线性表中的各个数据元素" << endl;
	Node<T>* p = front->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template<class T>
Node<T>* LinkList<T>::Get(int i)
{
	Node<T>* p = front->next;
	int j = 1;
	while (p && j != i)
	{
		p = p->next;
		j++;
	}
	return p;
}

template<class T>
int LinkList<T>::Locate(const T x)
{
	Node<T>* p = front->next;
	int j = 1;
	while (p)
	{
		if (p->data == x)
		{
			return j;
		}
		p = p->next;
		j++;
	}
	return -1;
} 

template<class T>
void LinkList<T>::Insert(int i, T x)
{
	Node<T>* p = front;
	if (i != 1)
	{
		p = Get(i - 1);
	}
	if (p)
	{
		Node<T>* s = new Node<T>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	else
	{
		throw"插入位置错误";
	}
}

template<class T>
T LinkList<T>::Delete(int i)
{
	Node<T>* p = front;
	if (i != 1)
	{
		p = Get(i - 1);
	}
	T x;
	if (!p || !p->next)
	{
		throw"位置异常";
	}
	else
	{
		Node<T>* q = p->next;
		p -> next = q -> next;
		x = q->data;
		delete q;
	}
	return x;
}

template<class T>
void LinkList<T>::Merge(LinkList<T> &a,LinkList<T> &b)
{
	Node<T>* r, * pa = a.front->next, * pb = b.front->next;
	a.front->next = NULL;
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			r = pa->next;
			pa->next = a.front->next;
			a.front->next = pa;
			pa = r;	
		}
		else
		{
			r = pb->next;
			pb->next = a.front->next;
			a.front->next = pb;
			pb = r;
		}
	}
	if (pa)
		pb = pa;
	while (pb)
	{
		r = pb->next;
		pb->next = a.front->next;
		a.front->next = pb;
		pb = r;
	}
	free(b.front);
}
 