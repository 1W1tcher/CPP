#include<iostream>
#include"1.h"

using namespace std;
int main()
{
	srand((int)time(NULL));
	LinkList<int> l1 = MakeGreatInt();
	LinkList<int> l2 = MakeGreatInt();
	LinkList<int> L;
	Solution<int> s;
	L.front = s.AddTwoNumbers(l1.front, l2.front);
	L.PrintList();
	return 0;
}