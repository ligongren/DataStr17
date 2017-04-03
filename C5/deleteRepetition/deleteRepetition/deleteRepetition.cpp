// deleteRepetition.cpp : 定义控制台应用程序的入口点。
//

//程序功能：输入一个顺序表，删除其中重复元素的数量，并统计删除过程中的执行次数


#include "stdafx.h"

#define elementType int

#include "list.h"

int main()
{
	elementType a[] = { 1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,8,9 };
	list L;
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		L.in(a[i]);
	}

	L.delRep();

	L.out();

	cout << endl;
	system("pause");
    return 0;
}
