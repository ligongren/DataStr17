// nonRecursion.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//������
//һ���ݹ����ĵȼ۷ǵݹ����
//ԭ����Ϊ��
//void P(int n)
//{
//	if (n > 0)
//	{
//		cout << n << " ";
//		P(n - 1);
//		P(n - 1);
//	}
//}

int main()
{
	int stack[100];
	int top;
	int n;
	top = 0;

	n = 4;
	
	int nReal = n;

L0:
	if (nReal > 0)
	{
		cout << nReal << " ";

		stack[++top] = nReal;
		stack[++top] = 1;
		nReal--;
		goto L0;
	L1:
		nReal = stack[top--];

		stack[++top] = nReal;
		stack[++top] = 2;
		nReal--;
		goto L0;
	L2:
		nReal = stack[top--];
	}

	if (top != 1)
	{
		switch (stack[top--])
		{
		case 1:
			goto L1;
			break;
		case 2:
			goto L2;
			break;
		}
	}

	cout << endl;
	system("pause");
	return 0;
}