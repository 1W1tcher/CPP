#include<iostream>
#include"排序.h"
using namespace std;
void insertTest(Node*front ,int array[],int n)//插入排序测试函数
{
	createLinkList(array, 10, front);
	insertSort(front);//
	printList(front);
	cout << endl;
}
void bubbleTest(Node* front, int array[], int n)//冒泡排序测试函数
{
	createLinkList(array, 10, front);
	bubbleSort(front,n);
	printList(front);
	cout << endl;
}
void quickTest(Node* front, int array[], int n)
{
	createLinkList(array, 10, front);
	quickSortAll(front->next);
	printList(front);
	cout << endl;
}
void selectTest(Node* front, int array[], int n)
{
	createLinkList(array, 10, front);
	selectSort(front);
	printList(front);
	cout << endl;
}
int main()
{
//测试数据：
	//正序：15, 35, 68, 76, 89, 103, 152, 361, 582, 1052
	//逆序：968, 756, 456, 105, 89, 46, 33, 15, 10, 1
	//随机数据：15, 34, 158, 32, 10, 468, 952, 1532, 12, 3
	int a[10] = { 15, 35, 68, 76, 89, 103, 152, 361, 582, 1052 };
	
	int b[10] = { 968, 756, 456, 105, 89, 46, 33, 15, 10, 1 };
	
	int c[10] = { 15, 34, 158, 32, 10, 468, 952, 1532, 12, 3 };
	
//一、插入排序
	cout << "插入排序结果：" << endl;
	Node* test01 = new Node;
	insertTest(test01, a, 10);

	Node* test02 = new Node;
	insertTest(test02, b, 10);

	Node* test03 = new Node;
	insertTest(test03, c, 10);
	cout << endl;
//二、冒泡排序
	cout << "冒泡排序结果：" << endl;
	Node* test04 = new Node;
	bubbleTest(test04, a, 10);

	Node* test05 = new Node;
	bubbleTest(test05, b, 10);

	Node* test06 = new Node;
	bubbleTest(test06, c, 10);
	cout << endl;
//三、快速排序
	cout << "快速排序结果：" << endl;
	Node* test07 = new Node;
	quickTest(test07, a, 10);

	Node* test08 = new Node;
	quickTest(test08, b, 10);

	Node* test09 = new Node;
	quickTest(test09, c, 10);
	cout << endl;
//四、简单选择排序
	cout << "简单选择排序结果：" << endl;
	Node* test10 = new Node;
	selectTest(test10, a, 10);

	Node* test11 = new Node;
	selectTest(test11, b, 10);

	Node* test12 = new Node;
	selectTest(test12, c, 10);
}