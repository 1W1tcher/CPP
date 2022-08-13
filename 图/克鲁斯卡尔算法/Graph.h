#pragma once
#include<iostream>
using namespace std;
const int MaxSize = 6, MAX_VERTEX = 6;
const int MAX_EDGE =7;

struct VEdge
{
	int fromV;
	int endV;
	int weight;
};

VEdge EdgeList[MAX_EDGE];
int vset[MAX_VERTEX];

template<class T>
class MGraph
{
public:
	MGraph(T a[], int n, int e);
	void Kruskal(VEdge EdgeList[], int nvex);

	T Vertex[MaxSize];//顶点
	int arc[MaxSize][MaxSize];//边
	int vertexNum, arcNum;//顶点数，边数
	int visited[MaxSize];//标志
};


template<class T>
MGraph<T>::MGraph(T a[], int n, int e)
{
	vertexNum = n;
	arcNum = e;
	for (int i = 0;i < vertexNum;i++)
	{
		Vertex[i] = a[i];
		visited[i] = 0;//为遍历增加标志
	}
	for (int i = 0;i < vertexNum;i++)
	{
		for (int j = 0;j < vertexNum;j++)
		{
			arc[i][j] = 0;//初始化边集
		}
	}
	for (int k = 0;k < arcNum;k++)
	{
		int i, j;
		cout << "请输入有边的两顶点" << endl;
		cin >> i >> j;
		int w;
		cout << "请输入边的权值" << endl;
		cin >> w;
		arc[i][j] = w;
		arc[j][i] = w;
	}
}

void BubbleSort(VEdge EdgeList[], int n)
{
	for (int i = 0;i < n - 1;i++)
	{
		for (int j = 0;j < n - i - 1;j++)
		{
			if (EdgeList[j].weight > EdgeList[j + 1].weight)
			{
				int temp = EdgeList[j].weight;
				EdgeList[j].weight = EdgeList[j + 1].weight;
				EdgeList[j + 1].weight = temp;
			}
		}
	}
}

template <class T>
void GenSortEdge(MGraph<T> G, VEdge EdgeList[])
{
	int k = 0, i, j;
	for (i = 0;i < G.vertexNum;i++)
	{
		for (j = 0;j <i;j++)
		{
			if (G.arc[i][j] != 0)
			{
				EdgeList[k].fromV = i;
				EdgeList[k].endV = j;
				EdgeList[k].weight = G.arc[i][j];
				k++;
			}
			
		}
	}
	BubbleSort(EdgeList, G.arcNum);
}

template<class T>
void MGraph<T>::Kruskal(VEdge EdgeList[], int nvex)
{
	int vset[MAX_VERTEX];
	for (int i = 0;i < nvex;i++)
	{
		vset[i] = i;//n个顶点独自构成n个连通分量
	}
	int k = 0;//最小生成树的第k条边
	int j = 0;//图的第j条边
	while (k < nvex-1 )
	{
		int m = EdgeList[j].fromV, n = EdgeList[j].endV;
		int sn1 = vset[m];
		int sn2 = vset[n];
		if (sn1 != sn2)
		{
			cout << 'V' << m << "->V" << n << endl;//Vm->Vn
			k++;//最小生成树增加一条边
			for (int i = 0;i < nvex;i++)
			{
				if (vset[i] == sn2)//编号为sn2连通分量的全部改为sn1
				{
					vset[i] = sn1;
				}
			}
		}
		j++;//访问图之边的序号加一
	}
}