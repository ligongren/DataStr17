// ex1.cpp : �������̨Ӧ�ó������ڵ㡣
//

//��ͷβ�ڵ��ѭ��˫���������


#include "stdafx.h"

#define elementType int

#include "doubleLinkedList.h"

int main()
{
	elementType x=0;				//���ڴ洢�������Ԫ��
	douLinLis linLis;					//ʵ��������������
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
