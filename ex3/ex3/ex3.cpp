// ex3.cpp : 定义控制台应用程序的入口点。
//

//程序功能：输入一串小写字母，实现并输出哈夫曼编码
//再输入哈夫曼编码，程序输出逆向生成对应的字符串

//删除hTree.h中207行，既可输出连续的，而不是每隔一个字符输出一个回车的哈夫曼编码

#include "stdafx.h"

#define eleType int
#define limit 100

#include "hTree.h"

int main()
{
	hTree tree;
	int a[26] = { 0 };
	char b[limit];

	cin >> b;

	int i = 0;
	while (b[i] != '\0')
	{
		a[b[i] - 'a']++;
		i++;
	}

	/*while ('a' <= b&&b <= 'z')
	{
		a[b - 'a']++;
		cin >> b; 
	}*/

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		if (a[i] != 0)
		{
			tree.in(a[i], i);
		}
	}

	tree.build();
	
	i = 0;
	while (b[i] != '\0')
	{
		tree.founded = false;
		tree.charToHCode(tree.first->node, -1, b[i] - 'a');
		i++;
	}

	cout << "请输入想转化成字符串的哈夫曼编码：";
	char hCode[limit * 5];
	cin >> hCode;

	i = 0;
	while (hCode[i] != '\0')
	{
		tree.hCodeToChar(hCode[i]-'0');
		i++;
	}
	cout << endl;

	system("pause");
    return 0;
}