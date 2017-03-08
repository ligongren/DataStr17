// C2_queue_array.cpp : 定义控制台应用程序的入口点。
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
		if ('0' <= inArray[i] && inArray[i] <= '9')	//当字符为数字时，直接入栈
			number.push(inArray[i] - '0');
			//从字符串获取数字，现在只能获取一个数字，sepNum函数负责将多个数字连起来
		else
		{
			int nowLev = charToNum(inArray[i]);		//存储当前运算符的优先级
			
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
			//此部分功能
			//当栈顶运算符优先级(topLev)比  栈顶-1运算符优先级(lastLev)  、 待入栈的运算符(nowLev) 优先级都高或相等时
				//栈顶运算符执行
				//不符合，则将待入栈运算符入栈，并退出循环
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