#include<iostream>
#include"turn.h"
using namespace std;

int main()
{
    unsigned long long NUM = 0;
    unsigned int n;
    cout << "请输入整数" << endl;
    cin >> NUM;
    cout << "请输入要转换成的进制：" << endl;
    cin >> n;
    Turn_n(NUM, n);
    return 0;
}