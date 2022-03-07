#pragma once
#include "map.h"
	node* Map::Erase(node* root, int key) {
		if (root == NULL)
			return root;
		if (key == root->key) {
			node* tmp;
			if (root->right == NULL)
				tmp = root->left;
			else {
				node* ptr = root->right;
				if (ptr->left == NULL) {
					ptr->left = root->left;
					tmp = ptr;
				}
				else {
					node* pmin = ptr->left;
					while (pmin->left != NULL) {
						ptr = pmin;
						pmin = ptr->left;
					}
					ptr->left = pmin->right;
					pmin->left = root->left;
					pmin->right = root->right;
					tmp = pmin;
				}
			}
			delete root;
			return tmp;
		}
		else if (key < root->key)
			root->left = Erase(root->left, key);
		else
			root->right = Erase(root->right, key);
		return root;
	}
	void Map::Print(node* root) const 
	{
		if (root != NULL)
		{
			cout << "Key - " << root->key << " String - " << root->value << endl;
			Print(root->left);
			Print(root->right);
		}
	}
	node* Map::Insert(int key, string value, node* root)
	{
		if (root == NULL) {
			root = new node;
			root->left = NULL;
			root->right = NULL;
			root->key = key;
			root->value = value;
		}
		else if (key < root->key)
			root->left = Insert(key, value, root->left);
		else
			root->right = Insert(key, value, root->right);
		return(root);
	}
	void Map::print() const
	{
		Print(root);
	}
	bool Map::insert(int key, string value)
	{
		if (root == NULL) {
			root = new node;
			root->left = NULL;
			root->right = NULL;
			root->key = key;
			root->value = value;
			return true;
		}
		string check = find(key);
		if (Insert(key, value, root))
		{
			return true;
		}
		else
			return false;
	}
	const string Map::find(int key) const
	{
		node* temp_root = root;
		while (temp_root)
		{
			if (temp_root->key > key)
			{
				temp_root = temp_root->left;
			}
			else if (temp_root->key < key)
			{
				temp_root = temp_root->right;
			}
			else
				return temp_root->value;
		}
		return "\0";
	}
	bool Map::erase(int key)
	{
		root = Erase(root, key);
		return root;
	}