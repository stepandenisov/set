#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
public:
	void iprint(node* root)
	{
		if (root == NULL)   // Базовый случай
		{
			return;
		}
		iprint(root->left);   //рекурсивный вызов левого поддерева
		cout << root->data << " ";
		iprint(root->right);  //рекурсивный вызов правого поддерева
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
	bool find(int key)
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
						tmproot = tmproot->left;
					}
				else if (tmproot->data < key)
					{
					if (tmproot->right == NULL)
					{
						tmproot->right = new node;
						tmproot = tmproot->right;
						break;
					}
						tmproot = tmproot->right;
					}
			}
			tmproot->data = key;
			tmproot->right = NULL;
			tmproot->left = NULL;
			return true;
		}
		else return false;
	}
	void print()
	{
		root->iprint(root);
	}
};

