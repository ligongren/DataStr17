// C2_queue_array.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#define ElementType int
#define maxlen 100

#include "charToNum.h"
#include "getNumber.h"
#include "error_code_s.h"
#include "StackArray.h"

int main()
{
	StackArray opeChar;
	StackArray number;

	char inArray[]="#4+5#";	

	int temp = charToNum('#');			//�洢��һ���ַ������ȼ�
	bool popLef = false;				//�洢�������Ƿ�Ӧ�ó�ջ

	for (int i = 0; i < strlen(inArray); i++)
	{
		//���ַ�Ϊ����ʱ��ֱ����ջ
		if ('0' <= inArray[i] && inArray[i] <= '9')
		{
			number.push(inArray[i] - '0');
		}

		//���ַ�Ϊ�����ʱ������һ������������ȼ��Ƚ�
		//��С�ڵ�����һ��������ջ
		//��������һ�������ж���һ���Ƿ�Ϊ����
			//��������������
			//�����������ջ���ڵ��ַ�
		else
		{
			while (true)
			{
				int nowOpe;
				opeChar.get_top(nowOpe);
				if (inArray[i] == ')')
					popLef = true;
				if (nowOpe == numLef && popLef == true)
					
			}
			opeChar.push(charToNum(inArray[i]));
		}
	}

	int y;
	opeChar.get_top(y);
	cout << y << endl;
	
	system("pause");
	return 0;
}