// C2_queue_array.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#define ElementType int
#define maxlen 100

#include "error_code_s.h"
#include "StackArray.h"
#include "linkedList.h"
#include "charToNum.h"

int main()
{
	linLis opeChar;
	linLis number;

	char inArray[]="#1+5*(2+3)*6/2-4#";	

	for (int i = 0; i < strlen(inArray); i++)
	{
		if ('0' <= inArray[i] && inArray[i] <= '9')	//���ַ�Ϊ����ʱ��ֱ����ջ
			number.push(inArray[i] - '0');
			//���ַ�����ȡ���֣�����ֻ�ܻ�ȡһ�����֣�sepNum�������𽫶������������
		else
		{
			int nowLev = charToNum(inArray[i]);		//�洢��ǰ����������ȼ�
			
			if (opeChar.empty())
			{
				opeChar.push(nowLev);
				continue;
			}
			int topLev;
			opeChar.get_top(topLev);
			if (topLev == 0)
			{
				opeChar.push(nowLev);
				continue;
			}

			int lastLev;
			opeChar.pop();
			opeChar.get_top(lastLev);
			opeChar.push(topLev);
			//----------------------------------------------------------------------------------------------
			//�˲��ֹ���
			//��ջ����������ȼ�(topLev)��  ջ��-1��������ȼ�(lastLev)  �� ����ջ�������(nowLev) ���ȼ����߻����ʱ
				//ջ�������ִ��
				//�����ϣ��򽫴���ջ�������ջ�����˳�ѭ��
			while (true)
			{
				if(topLev==-2 && nowLev==-1)
				{
					opeChar.pop();
					break;
				}
				if (lastLev <= topLev && topLev >= nowLev)
				{
					int a, b;
					number.get_top(b);
					number.pop();
					number.get_top(a);
					number.pop();
					switch (topLev)
					{
					case numPlus:
						number.push(a + b);
						break;
					case numSub:
						number.push(a - b);
						break;
					case numMul:
						number.push(a * b);
						break;
					case numDiv:
						number.push(a / b);
						break;
					}
					opeChar.pop();
					if (opeChar.empty())	break;
					opeChar.get_top(topLev);
					opeChar.pop();
					if (opeChar.empty())	break;
					opeChar.get_top(lastLev);
					opeChar.push(topLev);
				}
				else
				{
					if (inArray[i] != '(')
						opeChar.push(charToNum(inArray[i]));
					else
						opeChar.push(-2);
					break;
				}
			}
			//-------------------------------------------------------------------------------------------
		}
	}


	int y;
	number.get_top(y);
	cout << y << endl;
	
	system("pause");
	return 0;
}