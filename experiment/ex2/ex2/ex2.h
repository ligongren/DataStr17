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
	void preorder(bnode *parent);
	void inorder(bnode *parent);
	void postorder(bnode *parent);
	~tree();

private:
};

tree::tree()
{
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