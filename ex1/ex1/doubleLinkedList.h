#pragma once
struct dunode
{
	elementType data;
	dunode *prior;
	dunode *next;
};

class douLinLis
{
public:
	douLinLis();
	//int length()const;
	//void getElement(const int i, elementType &x)const;
	//dunode* locate(const elementType x)const;
	//void insert(const int i, const elementType x);
	//void deleteElement(const int i);
	void add(elementType x);							//增加一个元素
	void reverse();
	void show();
	~douLinLis();

private:
	int count;
	dunode *head;
	dunode *rear;
};

douLinLis::douLinLis()
{
	head = new dunode;
	rear = new dunode;
	head->prior = head;
	head->next = head;
	rear->prior = rear;
	rear->next = rear;
	count = 0;
}

//int douLinLis::length()const
//{
//	return count;
//}
//
//void douLinLis::getElement(const int i, elementType &x)const
//{
//	dunode *p = head->next;
//	int j = 1;
//	while (j != i&&p != NULL)
//	{
//
//	}
//}
//
//dunode* douLinLis::locate(const elementType x)const
//{
//
//}
//
//void douLinLis::insert(const int i, const elementType x)
//{
//
//}
//
//void douLinLis::deleteElement(const int i)
//{
//
//}

void douLinLis::add(elementType x)
{
	dunode *temp;
	temp = new dunode;
	temp->data = x;
	if (count == 0)
	{
		head->next = temp;
		rear->prior = temp;
		temp->prior = temp;
		temp->next = temp;
		count++;
		return;
	}
	temp->prior = rear->prior;
	rear->prior->next = temp;
	temp->next = head->next;
	rear->prior = temp;
	head->next->prior = temp;
	count++;
	return;
}

void douLinLis::reverse()
{
	dunode *temp;
	temp = new dunode;

	dunode *execute;						//正在执行逆置的元素的地址
	//dunode *last;							//上一个元素地址

	execute = head->next;				//从第一个元素开始执行
	//last = rear->next;						//上一个变量默认为rear元素

	do
	{
		temp->prior = execute->prior;
		temp->next = execute->next;

		execute->prior = temp->next;
		execute->next = temp->prior;
		 
		execute = temp->next;
	//	execute->next = last;
	//	last = execute;
	//	execute = temp;
	} while (execute != head->next);
	//execute->next = last;
	//head->next->next = rear;
	//temp = head->next;
	head->prior = rear->prior;
	rear->next = head->next;

	rear->prior = rear->next;
	head->next = head->prior;
	//rear = temp;
	return;
}

void douLinLis::show()
{
	dunode *execute;
	execute = head->next;
	cout << execute->data << '	' << execute << endl;
	while (execute != rear->prior)
	{
		execute = execute->next;
		cout << execute->data << '	' << execute << endl;
	}
	
	cout << head->next->prior->data << endl;
	cout << rear->prior->next->data << endl;

	return;
}

douLinLis::~douLinLis()
{
}