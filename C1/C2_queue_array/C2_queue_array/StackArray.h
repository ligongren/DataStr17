#pragma once

class StackArray
{
public:
	StackArray();
	~StackArray();
	bool			empty() const;
	bool			full() const;
	error_code		get_top(ElementType &x) const;
	error_code		push(const ElementType &x);
	error_code		pop();
private:
	int				count;
	ElementType		data[maxlen];
};

StackArray::StackArray()
{
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
	return true;
}


bool StackArray::full() const
{
	return true;
}


error_code StackArray::get_top(ElementType &x) const
{

}
error_code StackArray::push(const ElementType &x)
{

}
error_code StackArray::pop()
{
	
}