#pragma once
#include<iostream>
#include"speaker.h"
#include<vector>
#include<map>
using namespace std;
class SpeechManager
{
public:
	SpeechManager();//构造函数
	void showMenu();//菜单功能
	void exitSystem();//退出系统
	~SpeechManager();//析构函数
	void initSpeech();//初始化容器——清空容器
	vector<int> v1;//第一轮比赛选手编号容器
	vector<int> v2;//第一轮晋级选手编号容器
	vector<int> vVictory;//胜出（前三名）选手编号容器
	map<int,Speaker> m_Speaker;//编号索引容器
	int m_Index;//比赛轮数

};