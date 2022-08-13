#include<iostream>
#include <windows.h>
#include<stdio.h>
using namespace std;
class Elevator//电梯类
{
public:
	void graphical();//显示电梯图形
	void direction();//判断上下行的方向
	void select();//选择楼层
	void moveUp();//上行
	void moveDown();//下行
	int getfloor=1, getmove=1;//目标楼层和移动距离
	int current_floor=1;//当前所在楼层
private:
	void up();//上行动画
	void down();//下行动画
	int cnt=0;//运行次数
};
void Elevator::graphical()//显示图形菜单
{
	cnt++;
	if (cnt > 1)
	{
		Sleep(500);
	}
	system("cls");
	cout << "           欢迎使用本电梯~" << endl;
	cout << "           --" << "1、上行" << "--    " << endl;
	cout << "           --" << "2、下行" << "--    " << endl;
	cout << "           --" << "3、结束" << "--    " << endl;
}
void Elevator::direction()//选择上下行方向
{
	while (1)
	{
		cout << "请选择方向" << endl;
		cin >> getmove;
		if (getmove >= 1 && getmove <= 3)
		{
			break;
		}
		else
			cout << "输入有误，请重新输入~" << endl;
	}
}
void Elevator::select()//选择楼层
{
	/*cout << "请输入当前楼层" << endl;
	cin >> getfloor;
	if (getfloor > current_floor)
	{
		moveUp();
	}
	else if (getfloor < current_floor)
	{
		moveDown();
	}
	else if (getfloor == current_floor);*/
	cout << "请输入目标楼层：" << endl;
	cin >> getfloor;
}

void Elevator::moveUp()//上行
{
	if (getfloor > 100 || getfloor < 1)
	{
		cout << "输入有误，本栋楼只有100层" << endl;
	}
	else if (getfloor > current_floor)
	{
		up();
	}
	else if (getfloor <= current_floor)
	{
		cout << "输入有误，请重新输入" << endl;
	}
} 
void Elevator::moveDown()//下行
{
	if (getfloor > 100 || getfloor < 1)
	{
		cout<< "输入有误，本栋楼只有100层" << endl;
	}
	else if (getfloor < current_floor)
	{
		down();
	}
	else if (getfloor >= current_floor)
	{
		cout << "输入有误，请重新输入" << endl;
	}
}
void Elevator::up()//上行动画
{
	int i;
	system("cls");
	for (i = 0;current_floor < getfloor;current_floor++)
	{
		cout << "        --第" << current_floor <<"层--" << endl;
		cout << "           / \\   " << endl;
		cout << "          / | \\  " << endl;
		cout << "            |     " << endl;
		cout << "            |     " << endl;
		Sleep(2000);
		i++;
		/*if (i % 2 == 0);
		{
			system("cls");
		}*/
	}
	system("cls");
	cout << "电梯已到达第" << current_floor << "层" << endl;
}
void Elevator::down()//下行动画
{
	int i;
	system("cls");
	for (i = 0;current_floor > getfloor;current_floor--)
	{
		cout << "        --第" << current_floor << "层--" << endl;
		cout << "            |     " << endl;
		cout << "            |     " << endl;
		cout << "          \\ | /    " << endl;
		cout << "           \\ /    " << endl;
		Sleep(2000);
		i++;
		if (i % 2 == 0);
		{
			system("cls");
		}
	}
	system("cls");
	cout << "电梯已到达第" << current_floor << "层" << endl;
}