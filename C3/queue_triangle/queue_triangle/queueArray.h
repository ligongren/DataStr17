#pragma once
class queueArray
{
public:
	queueArray();
	~queueArray();
	bool empty() const;
	bool full() const;
	error_code_s get_front(elementType &x) const;		//取队头元素
	error_code_s append(const elementType x);			//入队
	error_code_s serve();												//出队
private:
	int count;						//队列中的元素数
	int rear;						//指向队尾元素
	int front;						//指向队头的前一个元素
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