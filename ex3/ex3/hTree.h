#pragma once

struct node
{
	eleType data;
	node *Lchild;
	node *Rchild;
};

struct listNode
{
	node *data;
	listNode *next;
};

class hTree
{
public:
	hTree();
	void in(eleType x);
	~hTree();

private:
	listNode *first, *last;
};

hTree::hTree()
{
	first = NULL;
	last = NULL;
}

void hTree::in(eleType x)
{
	node *in;
	in = new node;
	
	listNode *element;
	element = new listNode;

	in->data = x;
	in->Lchild = NULL;
	in->Rchild = NULL;

	element->data = in;
	element->next = NULL;

	if (!first)
	{
		first = element;
		last = element;
		return;
	}

	if (element->data->data <= first->data->data)
	{
		element->next = first;
		first = element;
		return;
	}

	listNode* compare;
	compare = first;

	while (compare != last)
	{
		if (compare->data->data <= element->data->data &&
			element->data->data <= compare->next->data->data)
		{
			break;
		}
		compare = compare->next;
	}
	
	element->next = compare->next;
	compare->next = element;

	if (element->next == NULL)
	{
		last = element;
	}

	return;
}

hTree::~hTree()
{
}