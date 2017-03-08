#pragma once
struct linLisNod				//Õ»½Úµã
{
	ElementType data;
	linLisNod* next;
};

class linLis
{
public:
	linLis();
	~linLis();
	bool empty()const;
	error_code_s get_top(ElementType &x) const;
	error_code_s push(const ElementType x);
	error_code_s pop();

private:
	linLisNod* top;
	int count;
};

linLis::linLis()
{
	count = 0;
	top = NULL;
}

linLis::~linLis()
{
	while (!empty())
	{
		pop();
	}
}

bool linLis::empty() const
{
	return count == 0;
}

error_code_s linLis::get_top(ElementType &x)const
{
	error_code_s underflow,success;
	underflow.write(1);
	success.write(0);
	if (empty()) return underflow;
	x = top->data;
	return success;
}

error_code_s linLis::push(const ElementType x)
{
	linLisNod* s;
	s = new linLisNod;
	s->data = x;
	s->next = top;
	top = s;
	count++;
	error_code_s success;
	success.write(0);
	return success;
}

error_code_s linLis::pop()
{
	error_code_s underflow, success;
	underflow.write(1);
	success.write(0);
	if (empty())
		return underflow;

	linLisNod* temp;
	temp = top->next;
	top->next = temp->next;
	delete temp;
	count--;
	return success;
}