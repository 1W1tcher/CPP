#include<iostream>
using namespace std;
struct Node//结点
{
	Node* next=NULL;
	Node* front = NULL;
	int data=0;
};
void swap(Node* a, Node* b)//交换函数
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}
void createLinkList(int a[],int n,Node* front)//建立链表
{
	Node* r = front;
	for (int i = 0;i < n;i++)
	{
		Node* p = new Node;
		p->data = a[i];
		p->front = r;
		r->next = p;
		r = p;
	}
}
void insertSort(Node* front)//插入排序
{
	Node* p = new Node;//建立工作指针
	if(front->next!=NULL)
		front->data = front->next->data;//头结点储存链表中第一个元素
	if(front->next->next!=NULL)
		p = front->next->next;//工作指针指向链表第二个元素
	while (p != NULL)//遍历整个链表
	{
		Node* r = new Node;//建立内部工作指针
		r = p;//指向工作指针p
		if (r->data < r->front->data)//若插入的元素小于它前一个元素，则开始寻找插入位置
		{
			front->data = r->data;//头结点储存插入的元素的值
			r->data = r->front->data;//有序链表倒数第二个元素后移
			Node* t = new Node;//建立工作指针t
			t=r->front->front;//t指向倒数第三个元素
			while (t != front&& front->data<t->data)//r向前遍历有序链表,若插入的元素仍较小，则一直向前遍历，直到找到插入位置
			{
				t->next->data = t->data;//链表元素后移
				t = t->front;//向前遍历
			}
			t->next->data = front->data;//插入到合适位置
		}
		p = p->next;
		
	}
}
void bubbleSort(Node* front,int n)//冒泡排序
{
	int i = n;
	while (i)
	{
		Node* p = new Node;
		p = front->next;//创建工作指针
		int bound = i;
		i = 0;//控制体外循环结束
		for (int j = 1;j < bound;j++)
		{
			
			if (p!= NULL && p->next != NULL)
			{
				if (p->data > p->next->data)
				{
					int temp = p->data;
					p->data = p->next->data;
					p->next->data = temp;
					i = j;//记下交换的记录的位置
				}
				p = p->next;
			}
		}
		
	}
}
Node* partition(Node* head, Node* tail)//划分
{
	Node* q = head;
	Node* p = head;
	int pivot = head->data;
	while (q != tail)
	{
		if (q->data < pivot)
		{
			p = p->next;
			swap(p, q);
		}
		q = q->next;
	}
	swap(p, head);
	return p;
}
Node* quickSort(Node* head, Node*tail)//快速排序
{
	if (head == tail)	return head;
	Node* mid = partition(head, tail);//找到中间值
	head = quickSort(head, mid);//队首到中间进行排序
	quickSort(mid->next, tail);//中间到队尾进行排序
	return head;
}
Node* quickSortAll(Node* head)//完整快排
{
	if (!head || !head->next) return head;
	return quickSort(head, nullptr);
}

Node* selectSort(Node* front)//选择排序
{
	Node* p = front->next;//已排序链表
	Node* q;
	Node* min;
	while (p)
	{
		q = p->next;//未排序链表
		min = p;
		while (q)//找到未排序中链表的最小值，加入已排序链表中
		{
			if (q->data < min->data)
				min = q;
			q = q->next;
		}
		if (min != p)
		{
			swap(min, p);//最小值加入已排序链表
		}
		p = p->next;
	}
	return front;
}


void printList(Node* front)//打印链表
{
	Node* p = new Node;
	p = front->next;
	while (p != NULL)
	{
		cout << p->data<<" ";
		p = p->next;
	}
}
