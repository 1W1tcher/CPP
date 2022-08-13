#include<iostream>
#include"链表.h"
using namespace std;

int main()
{
	double a[8] = { 15,354,64,21,0,496,54,31 };
	SeqList<double> list(a, 8);
	list.PrintList();

	list.Insert(5, 6.0);
	list.PrintList();

	int x = list.Delete(1);
	cout << "删除元素：" << x << endl;
	list.PrintList();

	int p = list.Locate(0);
	cout << "元素0的位置：" << p << endl;

	return 0;
}
