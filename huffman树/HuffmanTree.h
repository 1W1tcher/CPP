#pragma once
#include <iostream>
#include<string>
using namespace std;

struct Node
{
	int data;
	Node* next;
	int cnt=1;
};

struct HNode
{
	int weight;
	char data;
	int lchild, rchild, parent;
};

struct HCode
{
	char data;
	char code[100];
};

void Reverse(char ch[])
{
	
	int n = strlen(ch);
	char temp;
	for(int i=0;i<n;i++)
	{
		temp = ch[i];
		ch[i] = ch[n - 1 - i];
		ch[n - 1 - i] = temp;
	}
}

void SelectMin(HNode* hTree, int n, int& i1, int& i2)
{
	int i;
	//找一个比较的起始值
	for (i = 0;i < n;i++)//找i1
	{
		if (hTree[i].parent == -1)
		{
			i1 = i;
			break;
		}
	}
	for (i++;i < n;i++)//找i2
	{
		if (hTree[i].parent == -1)
		{
			i2 = i;
			break;
		}
	}
	if (hTree[i1].weight > hTree[i2].weight)
	{
		int j = i2;
		i2 = i1;
		i1 = j;
	}
	//找最小的两个
	for (i++;i < n;i++)
	{
		if (hTree[i].parent == -1)
		{
			if (hTree[i].weight < hTree[i1].weight)
			{
				i2 = i1;
				i1 = i;
			}
			else if (hTree[i].weight < hTree[i2].weight)
			{
				i2 = i;
			}
		}
	}
}

class HuffmanTree
{
	
public:
	HNode* huffTree;//huffman树
	HCode* HcodeTable;//huffman编码表
	int node;
	string code;
	void CreateHTree(char s[]);//创建huffman树
	void CreateCodeTable(int n);//创建编码表
	string Encode(string s);//编码
	string Decode(string d);//解码
	double Compress(char s[],string d);//统计压缩比
	~HuffmanTree()
	{
		delete huffTree;
	}
};


void HuffmanTree::CreateHTree(char s[])
{
	Node* front = new Node;
	Node* r = front;
	r->next = NULL;
	int n = 0;
	for(int i=0;s[i]!='\0';++i)
	{
		int count = 0;
		Node* p = new Node;
		p = front->next;
		while (p!= NULL)
		{
			if (s[i] == p->data)
			{
				p->cnt++;
				count++;
			}
			p = p->next;
		}
		if (count == 0)
		{
			Node *p1 = new Node;
			p1->data = s[i];
			r->next = p1;
			r = p1;
			r->next = NULL;
			n++;
		}
	}

	//根据权重数组a[1->n]初始化Huffman树
	huffTree = new HNode[2 * n - 1];
	Node* p = front->next;
	int i = 0;
	while(p)
	{
		huffTree[i].weight =p->cnt;
		huffTree[i].data =p->data;
		huffTree[i].lchild = -1;
		huffTree[i].rchild = -1;
		huffTree[i].parent = -1;
		p = p->next;
		i++;
	}
	int li=0, ri=0;
	for (int i = n;i < 2 * n - 1;i++)
	{
		//从0~i-1中选出两个全值最小的结点
		SelectMin(huffTree, i, li, ri);
		huffTree[li].parent = huffTree[ri].parent = i;
		huffTree[i].weight = huffTree[li].weight + huffTree[ri].weight;
		huffTree[i].lchild = li;
		huffTree[i].rchild = ri;
		huffTree[i].parent = -1;
	}
	node=n;
}

void HuffmanTree::CreateCodeTable(int n)
{
	HcodeTable = new HCode[n];//生成编码表
	for (int i = 0;i < n;i++)
	{
		HcodeTable[i].data =huffTree[i].data;
		int ic = i;
		int ip = huffTree[i].parent;
		int k = 0;
		while (ip != -1)
		{
			if (ic ==huffTree[ip].lchild)
			{
				HcodeTable[i].code[k] = '0';//左孩子标0
			}
			else
			{
				HcodeTable[i].code[k] = '1';//右孩子标1
			}
			k++;
			ic = ip;
			ip = huffTree[ic].parent;
		}
		HcodeTable[i].code[k] = '\0';
		//将编码字符逆置
		Reverse(HcodeTable[i].code);
		code += HcodeTable[i].code;
	}
}

string HuffmanTree :: Encode(string s)
{
	string d;
	for (int i = 0;s[i] != '\0';i++)
	{
		for (int j = 0;j<node;j++)
		{
			if (huffTree[j].data == s[i])
			{
				d += HcodeTable[j].code;
			}
		}
	}
	return d;
}

string HuffmanTree::Decode(string s)
{
	//s为编码串，d为解码后的字符串
	string d="";
	int i = 0;
	while(s[i]!='\0')
	{
		int k = 2 *node - 2;//根据结点在huffTree中的下标
		while (huffTree[k].lchild != -1)
		{
			if (s[i] == '0')
			{
				k = huffTree[k].lchild;
			}
			else
			{
				k = huffTree[k].rchild;
			}
			i++;
		}
		d += HcodeTable[k].data;
	}
	return d;
}

double HuffmanTree::Compress(char s[], string d)
{
	double s1 = strlen(s);
	double d1 = d.size();
	return s1/d1;
}