// nonRecursion.cpp : �������̨Ӧ�ó������ڵ㡣
//

//������
//һ���ݹ����ĵȼ۷ǵݹ����
//ԭ����Ϊ��

#include "stdafx.h"

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
	if (n>0)
	{
		cout << n;
		
		stack[top++] = n;
		n = n - 1;
		goto L0;

		stack[top++] = n;
		n = n - 1;
		goto L0;
	}
	if (top != )
	{
		n = stack[top--];
		goto L0;
	}

//L0:
//
//	if (nReal > 0)
//	{
//		cout << nReal<<" ";
//
//		stack[++top] = nReal;
//		nReal = nReal - 1;
//		goto L0;
//
//		stack[++top] = nReal;
//		nReal = nReal - 1;
//		goto L0;
//	}
//
//	if (top != 0)
//		n = stack[top--];
//		goto L0;



//
//	cout << endl;
//	system("pause");
	return 0;
}