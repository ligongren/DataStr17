#pragma once
struct queueLL
{
	elementType data;
	queueLL* next;
};

class queue
{
public:
	queue();
	~queue();
	bool empty()const;
	error_code_s get_front(elementType &x)const;
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

error_code_s queue::get_front(elementType &x)const
{
	if (!empty())
	{
		x = front->next->data;
		error_code_s success;
		success.write(0);
		return success;		
	}
	else
	{
		error_code_s overflow;
		overflow.write(1);
		return overflow;
	}
}

error_code_s queue::append(const elementType x)
{
	queueLL* s;
	s = new queueLL;
	s->data = x;
	s->next = front->next;
	front->next = s;
	count++;

	error_code_s success;
	success.write(0);
	return success;
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
		temp = front->next->next;
		delete front->next;
		front->next = temp;
		count--;
		error_code_s success;
		success.write(0);
		return success;
	}
}