// ex3.cpp : �������̨Ӧ�ó������ڵ㡣
//

//�����ܣ�����һ��Сд��ĸ��ʵ�ֲ��������������
//��������������룬��������������ɶ�Ӧ���ַ���

//ɾ��hTree.h��207�У��ȿ���������ģ�������ÿ��һ���ַ����һ���س��Ĺ���������

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

	cout << "��������ת�����ַ����Ĺ��������룺";
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