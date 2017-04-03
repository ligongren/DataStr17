// sequenceList.cpp : 定义控制台应用程序的入口点。
//

//
//程序功能：
//输入两个各以99为结尾的线性表，无论这两个线性表的顺序性如何，
//都输出一个综合两表中所有元素的顺序表。

#include "stdafx.h"

#define elementType int

#include "sequenceList.h"

int main()
{
	list a, b;
	list result;
	elementType x=-1;
	
	while (x != 99)
	{
		cin >> x;
		a.append(x);
	}

	x = -1;

	while (x != 99)
	{
		cin >> x;
		b.append(x);
	}

	while (!a.empty())
	{
		a.getFront(x);
		a.sever();
		result.appendNew(x);
	}

	while (!b.empty())
	{
		b.getFront(x);
		b.sever();
		result.appendNew(x);
	}

	result.show();

	cout << endl;
	system("pause");
    return 0;
}