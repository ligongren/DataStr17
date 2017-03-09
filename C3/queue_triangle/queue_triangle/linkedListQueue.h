#pragma once
struct queueLL
{
	queueLL* next;
	elementType data;
};

class queue
{
public:
	queue();
	~queue();
	bool empty()const;
	error_code_s getFront(elementType &x)const;
	error_code_s append(const elementType x);
	error_code_s serve();

private:
	queueLL* front;
	queueLL* rear;
	int count;
};

queue::queue()
{
	front = new queueLL;
	rear = front;
	count = 0;
}

queue::~queue()
{
	while (!empty())
	{
		serve();
	}
}

bool queue::empty()const
{
	return count == 0;
}

error_code_s queue::getFront(elementType &x)const
{

}

error_code_s queue::append(const elementType x)
{

}

error_code_s queue::serve()
{
	if (empty())
	{
		error_code_s overflow;
		overflow.write(1);
		return overflow;
	}
	else
	{
		queueLL* temp;
		temp = front;
		delete front->next;
		front = temp;
		error_code_s success;
		success.write(0);
		return success;
	}
}