#pragma once

struct node
{
	elementType data;
	node *next;
};

class list
{
public:
	list();
	const bool empty();
	void in(const elementType x);
	void delRep();
	void out();
	~list();

private:
	node *front;
	node *rear;
	int O;

};

list::list()
{
	front = new node;
	front->next = NULL;
	rear = front;
	O = 0;
}

inline const bool list::empty()
{
	return front->next == NULL;
}

inline void list::in(const elementType x)
{
	node *s;
	s = new node;
	s->data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
	return;
}

inline void list::delRep()
{
	node *now;
	node *reference;
	if (empty())
		return;
	now = front->next->next;
	reference = front->next;
	while (now != NULL)
	{
		O++;
		if (now->data == reference->data)
		{
			reference->next = now->next;
			delete now;
			now = reference->next;
		}
		else
		{
			reference = reference->next;
			now = now->next;
		}
	}
	return;
}

inline void list::out()
{
	while (!empty())
	{
		cout << front->next->data << " ";
		node* temp;
		temp = front->next->next;
		delete front->next;
		front->next = temp;
		if (temp == NULL)
			rear = front;
	}
	cout << endl << O;
	O = 0;
	return;
}

list::~list()
{
}