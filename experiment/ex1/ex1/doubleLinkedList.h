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
	void add(elementType x);							//����һ��Ԫ��
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
	count++;
	return;
}

void douLinLis::reverse()
{
	//dunode *execute;					//����ִ�����õ�Ԫ�صĵ�ַ
	//dunode *last;							//��һ��Ԫ�ص�ַ

	//execute = head->next;			//�ӵ�һ��Ԫ�ؿ�ʼִ��
	//last = rear->next;						//��һ������Ĭ��ΪrearԪ��

	//dunode *temp;

	//while (execute->next != rear->next)
	//{
	//	temp = execute->next;
	//	execute->next = last;
	//	last = execute;
	//	execute = temp;
	//}
	//execute->next = last;
	//head->next->next = rear;
	//temp = head->next;
	//head->next = rear;
	//rear = temp;
	return;
}

void douLinLis::show()
{
	dunode *execute;
	execute = head->next;
	cout << execute->data << '	' << execute << endl;
	while (execute != rear->prior->prior)
	{
		execute = execute->next;
		cout << execute->data << '	' << execute << endl;
	}

	cout<<endl;
	return;
}

douLinLis::~douLinLis()
{
}