#pragma once
class queueArray
{
public:
	queueArray();
	~queueArray();
	bool empty() const;
	bool full() const;
	error_code_s get_front(elementType &x) const;		//ȡ��ͷԪ��
	error_code_s append(const elementType x);			//���
	error_code_s serve();												//����
private:
	int count;						//�����е�Ԫ����
	int rear;						//ָ���βԪ��
	int front;						//ָ���ͷ��ǰһ��Ԫ��
	elementType data[maxLen];
};

queueArray::queueArray()
{
	count = 0;
	rear = 0;
	front = 0;
}

queueArray::~queueArray()
{
}

bool queueArray::empty()const
{
	if (count==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool queueArray::full()const
{
	if (count==maxLen)
	{
		return true;
	}
	else
	{
		return false;
	}
}

error_code_s queueArray::get_front(elementType &x)const
{
	if (empty())
	{
		error_code_s overflow;
		overflow.write(1);
		return overflow;
	}
	else
	{
		x = data[(front + 1) % maxLen];
		error_code_s success;
		success.write(0);
		return success;
	}
}

error_code_s queueArray::append(const elementType x)
{
	if (full())
	{
		error_code_s overflow;
		overflow.write(1);
		return overflow;
	}
	else
	{
		rear = (rear + 1) % maxLen;
		data[rear] = x;
		count++;
		error_code_s success;
		success.write(0);
		return success;
	}
}

error_code_s queueArray::serve()
{
	if (empty())
	{
		error_code_s overflow;
		overflow.write(1);
		return overflow;
	}
	else
	{
		front = (front +1) % maxLen;
		count--;
		error_code_s success;
		success.write(0);
		return success;
	}
}