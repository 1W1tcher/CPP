#include"Graph.h"
using namespace std;
int main()
{
	int a[6][6] = {
		0,1,0,0,1,0,
		1,0,0,0,1,1,
		0,0,0,1,0,1,
		0,0,1,0,0,1,
		1,1,0,0,0,0,
		0,1,1,1,0,0
	};//邻接矩阵

	//输入用例：1 0 1 3 2 2 4 0 3 4 1 4 5 1 5 5 2 6 5 3 7
	
	char b[6] = {'a','b','c','d','e','f'};
	MGraph<char> M(b,6,7);
	GenSortEdge(M, EdgeList);
	for (int i = 0;i < 7;i++)
	{
		cout << "边："<< EdgeList[i].fromV<<" "<< EdgeList[i].endV<<" "<<"权值："<<EdgeList[i].weight << endl;

	}
	M.Kruskal(EdgeList,6);
	return 0;
}