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
	linQueNod* front;				//头指针
	linQueNod* rear;					//尾指针
};

linQue::linQue()
{
	front = new linQueNod;								//建立头节点
	rear = front;													//尾结点指向头节点
	front->next = NULL;									//最后一个元素指向空
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