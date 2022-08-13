#include<iostream>
#include"5.4.h"
using namespace std;

int main()
{
	double a[8] = { 1,2,3,4,5,6,7,8 };
	LinkList<double> list(a, 8);
	list.PrintList();
	list.Reverse();
	list.PrintList();
	return 0;
}
