#pragma once

struct node
{
	eleType data;
	int alphabetNum;			//结点对应的英文字母编号
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
private:
	bool leafFlag;

	int passage[limit];
	node* hCodeNowNode;
	int top;
	bool sign;
public:
	listNode *first, *last;

	bool founded;

	hTree()
	{
		first = NULL;
		last = NULL;

		leafFlag = 0;

		top = 0;
	}
	void in(int showsNumbers, int alphabetNum)
	{
		node *in;
		in = new node;

		listNode *element;
		element = new listNode;

		in->data = showsNumbers;
		in->alphabetNum = alphabetNum;
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
	void build()
	{
		while (first->next != NULL)
		{
			node *add;
			add = new node;

			add->data = first->node->data + first->next->node->data;
			add->alphabetNum = 26;
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

			if (newLNode->next == NULL)
			{
				last = newLNode;
			}
		}
		return;
	}
	void hCodeToChar(int singleHCode)
	{
		if (sign == 0)
		{
			sign = 1;
			hCodeNowNode = first->node;
		}

		if (singleHCode == 0)
		{
			hCodeNowNode = hCodeNowNode->Lchild;
		}
		else
		{
			hCodeNowNode = hCodeNowNode->Rchild;
		}

		if (		hCodeNowNode->Rchild == NULL
			&&	hCodeNowNode->Lchild == NULL)
		{
			char out = hCodeNowNode->alphabetNum + 'a';
			cout << out;
			sign = 0;
		}
		
		return;
	}
	void charToHCode(node *parent,int direction, int targetAlpNum)
	{
		if (founded)
		{
			return;
		}

		if (parent != NULL)
		{
			passage[top++] = direction;
		}

		else
		{
			return;
		}

		if (parent->alphabetNum == targetAlpNum)
		{
			founded = true;
			for (int i = 0; i < top; i++)
			{
				if (passage[i] != -1)
				{
					cout << passage[i];
				}
			}
			cout << endl;
			top = 0;
			return;
		}

		charToHCode(parent->Lchild,0, targetAlpNum);
		charToHCode(parent->Rchild,1, targetAlpNum);

		if (founded)
		{
			return;
		}
		top--;

		return;
	}
	~hTree()
	{
	}
};