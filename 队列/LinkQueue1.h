#pragma once
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int v) {
		val = v;
		next = NULL;
	}
};
class Queue {
	int size;
	Node* head;
	Node* back;
public:
	Queue() {
		size = 0;
		head = back = NULL;
	}
	bool empty() {
		return size == 0;
	}
	Node* front() {
		return head;
	}
	Node* push_back(int v);


	void pop() {
		if (empty()) return;
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}

	int get_length();
};
Node* Queue::push_back(int v)
{
	if (size == 0) {

		head->next = head = back = new Node(v);
	}
	else if (size == 1) {
		head->next = back = new Node(v);
	}
	else {
		back->next = new Node(v);
		back = back->next;
	}
	size++;
	return back;
}
int Queue::get_length()
{
	int cnt=0;
	while (head != NULL)
	{
		head = head->next;
		cnt++;
	}
	return cnt;
}