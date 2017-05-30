// ex3.cpp : 定义控制台应用程序的入口点。
//

//程序功能：输入一串小写字母，实现其的哈夫曼编码，并输出哈夫曼编码和逆向生成的字符串

#include "stdafx.h"

#define eleType int
#define limit 100

#include "hTree.h"

int main()
{
	hTree tree;
	int a[26] = { 0 };
	char b[200];

	cin >> b;

	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
	{
		a[b[i] - 'a']++;
	}

	/*while ('a' <= b&&b <= 'z')
	{
		a[b - 'a']++;
		cin >> b; 
	}*/

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		tree.in(a[i],'a'+a[i]);
	}

	tree.build();
	
	tree.outNumbers(b);

	tree.outCharStr();

	//system("pause");
    return 0;
}