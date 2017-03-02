// C2_queue_array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define ElementType char
#define maxlen 100

#include "StackArray.h"

int main()
{

	StackArray operationalCharacter;
	StackArray parameter;

	char inArray[]="#4+5#";

	for (int i = 0; i < strlen(inArray); i++)
		cout << inArray[i]<<endl;

	for (int i = 0; i < strlen(inArray); i++)
	{
		if (i==0)
			continue;
		case:

	}

	cout << endl;
	system("pause");
	return 0;
}