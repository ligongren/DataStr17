// ex1.cpp : 定义控制台应用程序的入口点。
//

//带头尾节点的循环双链表的逆置


#include "stdafx.h"

#define elementType int

#include "doubleLinkedList.h"

int main()
{
	elementType x=0;				//用于存储待输入的元素
	douLinLis linLis;					//实例化逆置链表类
	while (x!=5)
	{
		cin >> x;
		linLis.add(x);
	}

	linLis.show();

	linLis.reverse();
	
	linLis.show();

    return 0;
}
