#pragma once

struct linQueNod
{
	elementType data;
	linQueNod* next;
};

class linQue
{
public:
	linQue();
	~linQue();
	bool empty() const;
	bool full() const;
	error_code_s getFront(elementType &x) const;
	error_code_s append(const elementType x);
	error_code_s sever();
private:
	linQueNod* front;				//ͷָ��
	linQueNod* rear;					//βָ��
};

linQue::linQue()
{
	front = new linQueNod;								//����ͷ�ڵ�
	rear = front;													//β���ָ��ͷ�ڵ�
	front->next = NULL;									//���һ��Ԫ��ָ���
}

linQue::~linQue()
{
	while (front!=NULL)
	{
		linQueNod* temp;
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool linQue::empty() const
{
	if (front->next == NULL)
	{
		return true;
	}
	return false;
}

bool linQue::full() const
{

}

error_code_s linQue::getFront(elementType &x)const
{

}

error_code_s linQue::append(const elementType x)
{

}

error_code_s linQue::sever()
{

}