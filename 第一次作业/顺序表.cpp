#include<iostream>
#include"Ë³Ðò±í.h"
using namespace std;

int main()
{
	double list[8] = { 15,354,64,21,0,496,54,31};
	SeqList<double> d(list,8);
	d.PrintList();
	return 0;
}
