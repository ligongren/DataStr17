#pragma once
struct node
{
	elementType data;
	node* next;
};

class list
{
public:
	list();
	bool empty() const;
	void getFront(elementType &x) const;
	void append(const elementType x);
	void appendNew(const elementType x);
	void sever();
	void show();
	~list();

private:
	node* front;
	node* rear;
	int count;
};

list::list()
{
	front = new node;
	rear = front;
	front->next = NULL;
}

bool list::empty() const
{
	return front->next == NULL;
}

void list::getFront(elementType &x) const
{
	if (!empty())
	{
		x = front->next->data;
	}
	return;
}

void list::append(const elementType x)
{
	node* s;
	s = new node;
	s->data = x;
	rear->next = s;
	s->next = NULL;
	rear = s;

	return;
}

void list::appendNew(const elementType x)
{
	node *s;
	node *last;
	s = new node;
	s->data = x;
	last = front;
	s->next = front->next;

	if (s->next == NULL)
	{
		last->next = s;
		return;
	}

	while (s->next->data < s->data)
	{
		last = s->next;
		s->next = s->next->next;
		if (s->next == NULL)
		{
			last->next = s;
			rear = s;
			return;
		}
	}

	last->next = s;

	return;
}

void list::sever()
{
	if (!empty())
	{
		node* temp;
		temp = front->next->next;
		delete front->next;
		front->next = temp;
		if (temp == NULL)
			rear = front;
	}
	return;
}

void list::show()
{
	while (!empty())
	{
		cout << front->next->data << " ";
		sever();
	}
	return;
}

list::~list()
{
	while (!empty())
	{
		sever();
	}
}