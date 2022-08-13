#pragma once
#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T data;
	Node<T>* next;
};

template<class T>
class LinkQueue
{
public:
	LinkQueue() { front = rear = new Node<T>; }
	~LinkQueue();
	void EnQueue(T x);
	T DeQueue();
	T GetFront();
	int GetLength();
	bool Empty() { return front == rear ? true : false; }
private:
	Node<T>* front;
	Node<T>* rear;
};
template<class T>
void LinkQueue<T>::EnQueue(T x)
{
	
	rear->next = new Node<T>;
	rear = rear->next;
	rear->data = x;
	rear->next = NULL;
	
}
template<class T>
T LinkQueue<T>::DeQueue()
{
	Node<T>* p = front->next;
	front->next = p->next;
	T x = p->data;
	delete p;
	if (front->next == NULL)
	{
		rear = front;
	}
	return x;

}
template<class T>
LinkQueue<T>::~LinkQueue()
{
	while (front != NULL)
	{
		rear = front->next;
		delete front;
		front = rear;
	}
}
template<class T>
T LinkQueue<T>::GetFront()
{
	return front->next->data;
}
template<class T>
int LinkQueue<T>::GetLength()
{
	int cnt=0;
	while (front != rear)
	{
		front = front->next;
		cnt++;
	}
	return cnt;
}