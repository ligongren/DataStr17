// ex2.cp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"


#define eleType char
#define limit 100

//#include <fstream>
//ifstream fin("in.txt");

#include "ex2.h"

int main()
{
	tree A;

	A.initial();

	//A.preorder(A.root);
	//cout << endl;
	//
	//A.inorder(A.root);
	//cout << endl;

	//A.postorder(A.root);
	//cout << endl;

	eleType data;
	cin >> data;
	A.find(A.root, data);
	A.include();
	

	system("pause");
    return 0;
}
