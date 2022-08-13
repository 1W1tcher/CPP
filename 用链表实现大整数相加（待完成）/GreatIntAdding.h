#pragma once
#include<iostream>
#include<ctime>
using namespace std;

template<class T>
struct Node
{
	T data=0;
	Node<T>* next;
	int cnt=0;
};

template<class T>
class LinkList
{
public:

	void PrintList();

	Node<T>* Get(int i);

	Node<T>* front;
	int N=0;
};

LinkList<int> MakeGreatInt()
{
	int N = rand() % 6+1;//生成1~50位
	LinkList<int> L1;//初始化链表
	L1.N = N;
	L1.front = new Node<int>;
	Node<int>* r = L1.front;
	Node<int>* s = new Node<int>;
	s->data = rand() % 9+1;//首位不能为0
	r->next = s;
	r = s;

	for (int i = 1;i < N;i++)//为每一数位生成随机数
	{
		Node<int>* s = new Node<int>;
		s->data = rand()%10;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L1;
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

LinkList<int> GreatIntAdding()
{
	LinkList<int> L1 = MakeGreatInt();
	cout << "随机整数1为：";
	L1.PrintList();
	LinkList<int> L2 = MakeGreatInt();
	cout << "随机整数2为：";
	L2.PrintList();
	LinkList<int> L;
	L.front = new Node<int>;
	L.front->next = NULL;
	//cout << "整数1的数位：" << L1.N << endl;
	//cout << "整数2的数位：" << L2.N << endl;

	if (L1.N >= L2.N)//L1的数位多于L2时
	{
		for (int i = 0;i <= L2.N;i++)
		{
			Node<int>* s = new Node<int>;
			s->next = L.front->next;
			if (s->next == NULL || s->next->cnt == 0)
			{
				if (L2.Get(L2.N)->data + L1.Get(L1.N)->data < 10)
				{
					s->data = L2.Get(L2.N)->data + L1.Get(L1.N)->data;
				}
				else
				{
					s->data = (L2.Get(L2.N)->data + L1.Get(L1.N)->data) % 10;
					s->cnt++;
				}
			}
			else
			{
				if (L2.Get(L2.N)->data + L1.Get(L1.N)->data + 1 < 10)
				{
					s->data = L2.Get(L2.N)->data + L1.Get(L1.N)->data + 1;
				}
				else
				{
					s->data = (L2.Get(L2.N)->data + L1.Get(L1.N)->data + 1) % 10;
					s->cnt++;
				}
			}
			L1.N--;
			L2.N--;
			L.front->next = s;
		}

		for (int i = L2.N+1;i < L1.N-1;i++)
		{
			Node<int>* s = new Node<int>;
			s->next = L.front->next;
			
			L.front->next = s;
			if (s->next->cnt == 0)
			{
				s->data = L1.Get(L1.N)->data;
			}
			else
			{
				if (L1.Get(L1.N)->data + 1 < 10)
				{
					s->data = L1.Get(L1.N)->data + 1;
				}
				else
				{
					s->data = (L1.Get(L1.N)->data + 1) % 10;
					s->cnt++;
				}
				
			}
			L1.N--;
		}
		Node<int>* s = new Node<int>;
		s->next = L.front->next;
		
		L.front->next = s;
		if (s->next->cnt == 0)
		{
			s->data = L1.Get(L1.N)->data;
		}
		else
		{
			if (L1.Get(L1.N)->data + 1 < 10)
			{
				s->data = L1.Get(L1.N)->data + 1;
			}
			else
			{
				s->data = (L1.Get(L1.N)->data + 1) % 10;
				Node<int>* s = new Node<int>;
				s->next = L.front->next;
				s->data = 1;
				L.front->next = s;
			}

		}
	}

	else//L1数位少于L2时
	{
		for (int i = 0;i <= L1.N;i++)
		{
			Node<int>* s = new Node<int>;
			s->next = L.front->next;
			if (s->next == NULL || s->next->cnt == 0)
			{
				if (L2.Get(L2.N)->data + L1.Get(L1.N)->data < 10)
				{
					s->data = L2.Get(L2.N)->data + L1.Get(L1.N)->data;
				}
				else
				{
					s->data = (L2.Get(L2.N)->data + L1.Get(L1.N)->data) % 10;
					s->cnt++;
				}
			}
			else
			{
				if (L2.Get(L2.N)->data + L1.Get(L1.N)->data + 1 < 10)
				{
					s->data = L2.Get(L2.N)->data + L1.Get(L1.N)->data + 1;
				}
				else
				{
					s->data = (L2.Get(L2.N)->data + L1.Get(L1.N)->data + 1) % 10;
					s->cnt++;
				}
			}
			L1.N--;
			L2.N--;
			L.front->next = s;
		}
		for (int i = L1.N+1;i < L2.N-1;i++)
		{
			Node<int>* s = new Node<int>;
			s->next = L.front->next;
			if (s->next == NULL || s->next->cnt == 0)
			{
				s->data = L2.Get(L2.N)->data;
			}
			else
			{
				if (L2.Get(L2.N)->data + 1 < 10)
				{
					s->data = L2.Get(L2.N)->data + 1;
				}
				else
				{
					s->data = (L2.Get(L2.N)->data + 1) % 10;
					s->cnt++;
				}
			}
			L2.N--;
			L.front->next = s;
		}
		Node<int>* s = new Node<int>;
		s->next = L.front->next;
		L.front->next = s;
		if (s->next->cnt == 0)
		{
			s->data = L2.Get(L2.N)->data;
		}
		else
		{
			if (L2.Get(L2.N)->data + 1 < 10)
			{
				s->data = L2.Get(L2.N)->data + 1;
			}
			else
			{
				s->data = (L2.Get(L2.N)->data + 1) % 10;
				Node<int>* s = new Node<int>;
				s->next = L.front->next;
				s->data = 1;
				L.front->next = s;
			}

		}
		
	}
	return L;
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