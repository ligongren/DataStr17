// ex3.cpp : �������̨Ӧ�ó������ڵ㡣
//

//�����ܣ�ʵ�ֹ�������

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

