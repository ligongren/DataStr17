// queue_triangle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define elementType int
#define maxLen 100

#include "error_code_s.h"
#include "linkedQueues.h"
#include "queueArray.h"
#include "linkedListQueue.h"

int main()
{
	int n = 8;
	int s1, s2;
	queueArray row;
	cout << 1 << endl;
	row.append(1);
	for (int i = 2; i <= n; i++)
	{
		s1 = 0;
		for (int j = 1; j <= i - 1; j++)
		{
			row.get_front(s2);
			row.serve();
			cout << s1 + s2 << '	';
			row.append(s1 + s2);
			s1 = s2;
		}
		cout << 1 << endl;
		row.append(1);
	}
    return 0;
}