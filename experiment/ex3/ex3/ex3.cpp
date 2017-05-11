// ex3.cpp : 定义控制台应用程序的入口点。
//

//程序功能：实现哈夫曼树

#include "stdafx.h"

#define eleType int
#define limit 100

#include "ex2.h"
#include "hTree.h"

int main()
{
	hTree tree;
	int a[] = { 3,4,5,6,8,10,12,18 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		tree.in(a[i]);
	}
	tree.build();
	tree.out();

	system("pause");
    return 0;
}

