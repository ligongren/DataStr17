// ex2.cp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"


#define eleType char

//#include <fstream>
//ifstream fin("in.txt");

#include "ex2.h"

int main()
{
	tree A;

	A.initial();

	A.preorder(A.root);
	cout << endl;
	
	A.inorder(A.root);
	cout << endl;

	A.postorder(A.root);
	cout << endl;

	system("pause");
    return 0;
}
