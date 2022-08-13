#include"speechManager.h"
#include"speaker.h"
SpeechManager::SpeechManager()
{
	this->initSpeech();
}
void SpeechManager::showMenu()
{
	cout << "-------------------------" << endl;
	cout << "----欢迎参加演讲比赛----" << endl;
	cout << "-----1.开始演讲比赛-----" << endl;
	cout << "-----2.查看往届记录-----" << endl;
	cout << "-----3.清空比赛记录-----" << endl;
	cout << "-----0.退出比赛程序-----" << endl;
	cout << "-------------------------" << endl;
	cout << endl;
}
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}
void SpeechManager::initSpeech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
}
SpeechManager::~SpeechManager()
{

}