// sequenceList.cpp : �������̨Ӧ�ó������ڵ㡣
//

//
//�����ܣ�
//������������99Ϊ��β�����Ա��������������Ա��˳������Σ�
//�����һ���ۺ�����������Ԫ�ص�˳���

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