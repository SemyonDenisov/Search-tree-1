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
public:
	Map()
	{
		root = NULL;
	}
	void print()
	{
		node* temp_root = root;
		while (temp_root)
		{
			cout << "Key - " << temp_root->key << " String - " << temp_root->value<<endl;
			if (temp_root->left)
			{
				temp_root = temp_root->left;
			}
			else 
				break;
		}
		if (root->right)
		{
			temp_root = root->right;
			while (temp_root)
			{
				cout << "Key - " << temp_root->key << " String - " << temp_root->value << endl;
				if (temp_root->right)
				{
					temp_root = temp_root->right;
				}
				else
					break;
			}
		}
	}
	bool insert(int key, string value)
	{
		if (root == NULL) {
			root = new node;
			root->left = NULL;
			root->right = NULL;
			root->key = key;
			root->value = value;
			return true;
		}
		node* check = find(key);
		if (!check)
		{
			call_insert(key, value, root);
			return true;
		}
		else
			return false;
	}
	node* call_insert(int key, string value,node*root)
	{
		if (root == NULL) {
			root = new node;
			root->left = NULL;
			root->right = NULL;
			root->key = key;
			root->value = value;
		}
		else if (key < root->key)   // условие добавление левого потомка
			root->left = call_insert(key, value,root->left);
		else    // условие добавление правого потомка
			root->right = call_insert(key, value, root->right);
		return(root);

	}
	node* find(int key)
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
				return temp_root;
		}
		return nullptr;
	}
	//bool erase(int key, node* root)
	//{
	//	node* eras = find(key, root);

	//}
};
int main()
{
	Map A;
	A.insert(1,"Senja");
	A.insert(2, "Pops");
	A.insert(-1, "hueps");
	A.insert(-2, "d");
	A.insert(3, "Styopakazel");
	A.print();
	return 0;
}