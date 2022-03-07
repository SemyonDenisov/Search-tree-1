#pragma once
#include <iostream>
#include <iterator>
#include <string>
using namespace std;
struct node {
	node* left;
	node* right;
	int key;
	string value;
};

class Map
{
private:
	node* root;
	node* Erase(node* root, int key);
	void Print(node* root) const;
	node* Insert(int key, string value, node* root);
	void Delete(node* root);
public:
	Map()
	{
		root = NULL;
	}
	~Map()
	{
		Delete(root);
	}
	void print() const;
	bool insert(int key, string value);
	const string find(int key) const;
	bool erase(int key);

};