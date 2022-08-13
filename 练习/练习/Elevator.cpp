#include"Elevator.h"
using namespace std;
int main()
{
	Elevator test01;
	while (test01.getmove != 3)
	{
		test01.graphical();
		cout << "当前楼层:第" <<test01.current_floor<<"层"<< endl;
		test01.direction();
		if (test01.getmove != 3)
		{
			test01.select();
			if (test01.getmove == 1)
			{
				test01.moveUp();
			}
			else if (test01.getmove == 2)
			{
				test01.moveDown();
			}
		}
		else
		{
			cout << "程序已退出" << endl;
			continue;
		}
	}
	return 0;
}