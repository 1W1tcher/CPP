#include<iostream>
#include"5.3.h"
using namespace std;

int main()
{
	double a[8] = {1,2,3,4,5,6,7,8 };
	double b[7] = {1,2,6,8,10,15,18};
	LinkList<double> list(a, 8);
	LinkList<double> list2(b, 7);
	/*list.PrintList();

	list.Insert(5, 6.0);
	list.PrintList();

	int x = list.Delete(1);
	cout << "删除元素：" << x << endl;
	list.PrintList();

	int p = list.Locate(0);
	cout << "元素0的位置：" << p << endl;*/

	list.Merge(list2);
	list.PrintList();
	return 0;
}
