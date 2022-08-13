#pragma once
#include<iostream>
#include"链表.h"
struct term
{
	float coef;//系数
	int expn;//指数
	term* next;
};
class Polynomial
{
public:
	Polynomial()
	{
		front = new term;
		front->next = NULL;
	}
	Polynomial( int n,const double a[] );
	
private:
	term *front;
};


Polynomial::Polynomial(int n,const double a[])
{
	front = new term;

}