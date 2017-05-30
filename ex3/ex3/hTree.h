#pragma once

struct node
{
	eleType data;
	char y;								//结点对应的英文字母
	char passage[10];				//结点字母对应的哈夫曼编码
	int layer;							//当前结点哈夫曼编码运算的位数
	node *Lchild;
	node *Rchild;
};

struct listNode
{
	node *node;
	listNode *next;
};

class hTree
{
public:
	hTree();
	void in(eleType x,char y);
	void build();
	void outNumbers(char *in);
	void outCharStr();
	~hTree();

private:
	listNode *first, *last;
};

hTree::hTree()
{
	first = NULL;
	last = NULL;
}

void hTree::in(eleType x,char y)
{
	if (x == 0)
	{
		return;
	}

	node *in;
	in = new node;
	
	listNode *element;
	element = new listNode;

	in->data = x;
	in->y = y;
	in->Lchild = NULL;
	in->Rchild = NULL;

	element->node = in;
	element->next = NULL;

	if (!first)
	{
		first = element;
		last = element;
		return;
	}

	if (element->node->data <= first->node->data)
	{
		element->next = first;
		first = element;
		return;
	}

	listNode* compare;
	compare = first;

	while (compare != last)
	{
		if (compare->node->data <= element->node->data &&
			element->node->data <= compare->next->node->data)
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

void hTree::build()
{
	while (first->next!=NULL)
	{
		node *add;
		add = new node;

		add->data = first->node->data + first->next->node->data;
		add->y = 0;
		add->Lchild = first->node;
		add->Rchild = first->next->node;

		listNode *newLNode;
		newLNode = new listNode;
		newLNode->node = add;
		newLNode->next = NULL;
		
		listNode *del;
		del = first;
		first = first->next->next;
		if (first == NULL)
		{
			first = newLNode;
			return;
		}
		delete del->next;
		delete del;

		if (newLNode->node->data <= first->node->data)
		{
			newLNode->next = first;
			first = newLNode;
			continue;
		}

		listNode* compare;
		compare = first;

		while (compare != last)
		{
			if (compare->node->data <= newLNode->node->data &&
				newLNode->node->data <= compare->next->node->data)
			{
				break;
			}
			compare = compare->next;
		}

		newLNode->next = compare->next;
		compare->next = newLNode;

		if (newLNode ->next == NULL)
		{
			last = newLNode;
		}
	}
	return;
}

void hTree::outNumbers(char *in)
{
	
}

void hTree::outCharStr()
{

}

hTree::~hTree()
{
}