#include<iostream>
#include"HuffmanTree.h"
int main()
{
	HuffmanTree h;
	cout << "————测试用例————" << endl;
	char s[] = "I love data Structure,I love Computer.I will try my best to study data Structure.";
	cout << "输入的字符串为：" << s << endl;
	h.CreateHTree(s);
	int n = h.node;
	cout <<"共有"<< n <<"个字符元素"<< endl;
	h.CreateCodeTable(n);
	cout << "编码表为：" << endl;
	for (int i = 0;i < n;i++)
	{
		cout << h.HcodeTable[i].data << " " <<h.HcodeTable[i].code<< endl;
	}

	string d=h.Encode("I love data Structure,I love Computer.I will try my best to study data Structure.");
	cout << "编码后的字符串为：" << d << endl;
	cout << "压缩比：" << h.Compress(s, d)<< endl;
	return 0;
}