// deleteRepetition.cpp : �������̨Ӧ�ó������ڵ㡣
//

//�����ܣ�����һ��˳���ɾ�������ظ�Ԫ�ص���������ͳ��ɾ�������е�ִ�д���


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
