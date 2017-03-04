// C2_queue_array.cpp : 定义控制台应用程序的入口点。
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

	int temp = charToNum('#');			//存储上一个字符的优先级
	bool popLef = false;				//存储左括号是否应该出栈

	for (int i = 0; i < strlen(inArray); i++)
	{
		//当字符为数字时，直接入栈
		if ('0' <= inArray[i] && inArray[i] <= '9')
		{
			number.push(inArray[i] - '0');
		}

		//当字符为运算符时，与上一个运算符的优先级比较
		//若小于等于上一个，则入栈
		//若大于上一个，则判断下一个是否为数字
			//如果是则进行运算
			//如果不是则入栈现在的字符
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