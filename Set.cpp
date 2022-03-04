#include "Set.h"
node node::operator=(const node& another)
{
	this->data = another.data;
	this->left = another.left;
	this->right = another.right;
	return *this;
}
void node :: print_tree(node* root) const
{
	if (root == NULL)
	{
		return;
	}
	print_tree(root->left);
	cout << root->data << ", ";
	print_tree(root->right);
}

void node :: clear_tree(node*& root)
{
	if (root)
	{
		if (root->left) clear_tree(root->left);
		if (root->right) clear_tree(root->right);
		root = NULL;
	}
}

Set::Set()
{
	root = NULL;
}

bool Set::find(int key) const
{
	if (!root) return false;
	node* tmproot = root;
	while (tmproot)
	{
		if (key > tmproot->data)
		{
			tmproot = tmproot->right;
		}
		else if (key < tmproot->data)
		{
			tmproot = tmproot->left;
		}
		else if (key == tmproot->data) return true;
	}
	return false;
}

bool Set :: insert(int key)
{
	if (!root)
	{
		root = new node;
		root->data = key;
		root->right = NULL;
		root->left = NULL;
		return true;
	}
	node* tmproot = root;
	while (tmproot)
	{
		if (tmproot->data > key)
		{
			if (tmproot->left == NULL)
			{
				tmproot->left = new node;
				tmproot = tmproot->left;
				break;
			}
			else tmproot = tmproot->left;
		}
		else if (tmproot->data < key)
		{
			if (tmproot->right == NULL)
			{
				tmproot->right = new node;
				tmproot = tmproot->right;
				break;
			}
			else tmproot = tmproot->right;
		}
		else if (tmproot->data == key) return false;
	}
	tmproot->data = key;
	tmproot->right = NULL;
	tmproot->left = NULL;
	return true;
}

std::ostream& operator<<(std::ostream& out, Set& s)
{
	if (s.root)
	{
		cout << "{";
		s.root->print_tree(s.root);
		cout << "\b\b}";
	}
	return out;
}

bool Set :: erase(int key)
{
	node* tmproot = root, * parent = NULL;
	while (tmproot)
	{
		if (tmproot->data > key)
		{
			parent = tmproot;
			tmproot = tmproot->left;
		}
		else if (tmproot->data < key)
		{
			parent = tmproot;
			tmproot = tmproot->right;
		}
		else if (tmproot->data == key) break;
	}
	if (!tmproot) return false;
	if (!tmproot->right && !tmproot->left) // Лист
	{
		if (parent && (parent->data > tmproot->data)) parent->left = NULL;
		else if (parent && (parent->data < tmproot->data)) parent->right = NULL;
		else if (tmproot == root) root = NULL;
		delete tmproot;
		return true;
	}
	else if (!tmproot->left) // Нет левого, есть правое
	{
		if (parent && (parent->data > tmproot->data)) parent->left = tmproot->right;
		else if (parent && (parent->data < tmproot->data)) parent->right = tmproot->right;
		else if (tmproot == root) root = root->right;
		delete tmproot;
		return true;
	}
	else if (!tmproot->right) // Нет правого, есть левое
	{
		if (parent && (parent->data > tmproot->data)) parent->left = tmproot->left;
		else if (parent && (parent->data < tmproot->data)) parent->right = tmproot->left;
		else if (tmproot == root) root = root->left;
		delete tmproot;
		return true;
	}
	else // Есть оба поддерева
	{
		node* ernode = tmproot->right;
		while (ernode->left)
			ernode = ernode->left;
		int value = ernode->data;
		erase(ernode->data);
		tmproot->data = value;
		return true;
	}
}

void Set :: clear()
{
	root->clear_tree(root);
}

Set :: ~Set()
{
	clear();
}