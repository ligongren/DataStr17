// ex3.cpp : �������̨Ӧ�ó������ڵ㡣
//

//�����ܣ�����һ��Сд��ĸ��ʵ����Ĺ��������룬�����������������������ɵ��ַ���

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