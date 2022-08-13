#include<iostream>
#include"LinkQueue1.h"
using namespace std;

int main() {
	Queue queue;
	queue.push_back(1);
	queue.push_back(2);
	queue.push_back(3);
	cout << queue.front()->val << endl;
	queue.pop();
	cout << queue.front()->val << endl;
	cout << queue.get_length() << endl;
	return 0;
}
