// C2_queue_array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define ElementType int
#define maxlen 100


#define numPou 0

#define numPlus 1
#define numSub 2

#define numMul 3
#define numDiv 4

#define numLef 5
#define numRig 6

//#include "getNumber.h"
#include "error_code_s.h"
#include "StackArray.h"

int main()
{

	StackArray operationalCharacter;
	StackArray number;

	char inArray[]="#4+5#";

	for (int i = 0; i < strlen(inArray); i++)
	{
		if ('0' <= inArray[i] && inArray[i] <= '9')
		{
			//getNumber(&number, inArray[i]);
			number.push(inArray[i]-'0');
		}
		else
		{
			switch (inArray[i])
			{
			default:
				break;
			case '#':
				operationalCharacter.push(numPou);
				break;
			case '+':
				operationalCharacter.push(numPou);
				break;
			case '-':
				operationalCharacter.push(numPou);
				break;
			case '*':
				operationalCharacter.push(numPou);
				break;
			case '/':
				operationalCharacter.push(numPou);
				break;
			}
			operationalCharacter.push(inArray[i]);
		}
		while (true)
		{

		}
	}

	cout << endl;
	system("pause");
	return 0;
}