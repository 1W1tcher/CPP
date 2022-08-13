#include<iostream>
using namespace std;
#define MAXVEX 100

//边表
struct EdgeNode
{
	int adjvex;
	EdgeNode* next;
};

//顶点
struct VexNode
{
	int data;
	EdgeNode* first;
};

//邻接表
struct GraAdjList
{
	VexNode AdjList[MAXVEX];
	int vexnum;
	int edgenum;
};
//创建邻接表
void Create(GraAdjList& g)
{
	int i, j, k;
	EdgeNode *e = NULL;
	EdgeNode *q = NULL;
	cout << "请输入顶点数和边数：" << endl;
	cin >> g.vexnum >> g.edgenum;
	cout << "请输入顶点信息：" << endl;
	for (k = 0;k < g.vexnum;k++)
	{
		cin >> g.AdjList[k].data;
		g.AdjList[k].first = NULL;
	}
	//建立边表
	for (k = 0;k < g.edgenum;k++)
	{
		cout << "请输入边(vi,vj)的下标vi,vj" << endl;
		cin >> i >> j;
		e = new EdgeNode;
		e->adjvex = j;
		e->next = g.AdjList[i].first;
		g.AdjList[i].first = e;
		//无向图
		q = new EdgeNode;
		q->adjvex = i;
		q->next = g.AdjList[j].first;
		g.AdjList[j].first = q;
	}
}
//输出邻接表
void Print(GraAdjList& g)
{
	cout << endl << "邻接表：" << endl;
	EdgeNode* p;
	for (int i = 0;i < g.vexnum;i++)
	{
		cout << "顶点" << g.AdjList[i].data << ":";
		for (p = g.AdjList[i].first;p;p = p->next)
			cout << p->adjvex << " ";
		cout << endl;
	}
}
//全局变量
int Visited[MAXVEX];
//深度优先的遍历的非递归算法
void DFS1(GraAdjList& g, int v)
{
	int s[MAXVEX];//栈
	int top = -1;//栈顶位置
	int j;
	EdgeNode* p;
	cout << g.AdjList[v].data << " ";//输出当前顶点的信息
	Visited[v] = 1;//表示已访问
	s[++top] = v;//进栈
	while (top != -1)//栈不为空就一直循环
	{
		v = s[top];//取栈顶元素
		p = g.AdjList[v].first;//到相连的下一顶点
		while (p)//p不为空就一直循环
		{
			j = p->adjvex;//下一顶点的信息
			if (Visited[j] == 0)//没访问过
			{
				cout << g.AdjList[j].data << " ";
				Visited[j] = 1;//表示已访问
				s[++top] = j;//进栈
				p = g.AdjList[j].first;//到相连的下一顶点
			}
			else
				p = p->next;//访问过就到下一条边
		}
		top--;//出栈
	}
}
int main()
{
	//测试用例：9 10 0 1 2 3 4 5 6 7 8 0 1 0 2 1 3 1 4 2 5 2 6 5 6 3 7 4 7 7 8
	GraAdjList G;
	Create(G);
	Print(G);
	int i;
	//初始化
	for (i = 0;i < G.vexnum;i++)
		Visited[i] = 0;
	cout << "深度优先遍历(非递归)：" << endl;
	DFS1(G,0);
	cout << endl;
	return 0;
}