#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
public:
	node operator=(node &another)
	{
		this->data = another.data;
		this->left = another.left;
		this->right = another.right;
		return *this;
	}
	void print_tree(node* root) const
	{
		if (root == NULL)
		{
			return;
		}
		print_tree(root->left);
		cout << root->data << ", ";
		print_tree(root->right);
	}
};
class Set
{
private:
	node* root;
public:
	Set()
	{
		root = NULL;
	}
	bool find(int key) const
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
	bool insert(int key)
	{	
		if (!root)
		{
			root = new node;
			root->data = key;
			root->right = NULL;
			root->left = NULL;
			return true;
		}
		if (!find(key))
		{
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
			}
			tmproot->data = key;
			tmproot->right = NULL;
			tmproot->left = NULL;
			return true;
		}
		else return false;
	}
	void print() const
	{
		cout << "{";
		root->print_tree(root);
		cout << "\b\b}";
	}
	bool erase(int key)
	{
		node* tmproot = root, *parent = NULL;
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
};

