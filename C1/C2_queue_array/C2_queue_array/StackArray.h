#pragma once

#include "error_code_s.h"

class StackArray
{
public:
					StackArray();
					~StackArray();
	bool			empty() const;
	bool			full() const;
	error_code_s	get_top(ElementType &x) const;
	error_code_s	push(const ElementType &x);
	error_code_s	pop();
private:
	int				count;
	ElementType		data[maxlen];
};

StackArray::StackArray()
{
	count = 0;
}
StackArray::~StackArray()
{
}
//inline bool stackarray::empty() const
//{
//	return false;
//}
bool StackArray::empty() const
{
	if (count==0)
		return true;
	else
		return false;
}
bool StackArray::full() const
{
	if (count>=maxlen)
		return true;
	else
		return false;
}
error_code_s StackArray::get_top(ElementType &x) const
{
	if (empty())
	{
		error_code_s underflow;
		underflow.write(1);
		return underflow;
	}
	else
	{
		x = data[count - 1];
		error_code_s success;
		success.write(0);
		return success;
	}
}
error_code_s StackArray::push(const ElementType &x)
{
	if (full())
	{
		error_code_s overflow;
		overflow.write(2);
		return overflow;
	}
	else
	{
		count++;
		data[count - 1] = x;

		error_code_s success;
		success.write(0);
		return success;
	}
}
error_code_s StackArray::pop()
{
	if (empty())
	{
		error_code_s underflow;
		underflow.write(2);
		return underflow;
	}
	else
	{
		count--;

		error_code_s success;
		success.write(0);
		return success;
	}	
}