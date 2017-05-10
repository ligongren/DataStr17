#pragma once
struct bnode
{
	eleType data;
	bnode *Lchild;
	bnode *Rchild;
};

class tree
{
public:
	tree();
	void initial();
	void insert(bnode** parent);
	bnode *root;
	void find(bnode *parent, eleType &target);
	void include();
	void preorder(bnode *parent);
	void inorder(bnode *parent);
	void postorder(bnode *parent);
	~tree();

private:
	bnode* passage[limit];
	int top;
	bool sign;
};

tree::tree()
{
	sign = false;
	top = 0;
}

void tree::initial()
{
	eleType x;
	x = cin.get();
	root = new bnode;
	root->data = x;

	root->Lchild = new bnode;
	root->Rchild = new bnode;

	insert(&root->Lchild);
	insert(&root->Rchild);

	return;
}

//这个函数使用了指针的指针，很有意思。
void tree::insert(bnode** parent)
{
	eleType x;
	x = cin.get();
	if (x == '_')
	{
		delete *parent;
		*parent = NULL;
	}
	else
	{
		bnode *temp = *parent;
		temp->data = x;

		temp->Lchild = new bnode;
		temp->Rchild = new bnode;
		
		insert(&temp->Lchild);
		insert(&temp->Rchild);
	}
	return;
}

void tree::find(bnode *parent, eleType &target)
{
	if (sign)
	{
		return;
	}

	if (parent)
	{
		passage[top++] = parent;
	}

	else
	{
		return;
	}

	if (parent->data == target)
	{
		sign = true;
		cout << endl;
		for (int i = 0; i < top; i++)
		{
			cout << passage[i]->data;
		}
		top = 0;
		cout << endl;
		return;
	}
	
	find(parent->Lchild, target);
	find(parent->Rchild, target);
	
	top--;

	return;
}

void tree::include()
{
	if (sign == false)
		cout << "元素不存在。" << endl;
	return;
}

void tree::preorder(bnode *parent)
{
	if (!parent)
		return;
	cout << parent->data;
	preorder(parent->Lchild);
	preorder(parent->Rchild);
	return;
}

void tree::inorder(bnode *parent)
{
	if (!parent)
		return;
	inorder(parent->Lchild);
	cout << parent->data;
	inorder(parent->Rchild);
	return;
}

void tree::postorder(bnode *parent)
{
	if (!parent)
		return;
	postorder(parent->Lchild);
	postorder(parent->Rchild);
	cout << parent->data;
	return;
}

tree::~tree()
{
}