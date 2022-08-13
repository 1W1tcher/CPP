#include<iostream>
#include"speechManager.h"
using namespace std;

int main()
{
	SpeechManager sm;
	
	int choice = 0;
	while (true)
	{
		sm.showMenu();

		cout << "请输入您的选择：";

		cin >> choice;
		
		switch (choice)
		{
		case 1://开始比赛
			break;
		case 2://查看往届记录
			break;
		case 3://清空比赛记录
			break;
		case 0://退出系统
			sm.exitSystem();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
	return 0;
}