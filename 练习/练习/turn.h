#include <iostream>
using namespace std;

void Turn_n(unsigned long long NUM, unsigned int n)
{
    int i = 0;
    unsigned long long k = 0;
    unsigned int Turnres[64] = {};

    do {
        Turnres[i] = NUM % n;
        NUM /= n;
        i++;
    } while (NUM != 0);
    for (i--; i >= 0; i--)//从后向前输出
    {
        cout << Turnres[i];
    }
    cout << endl;
    return;
}

