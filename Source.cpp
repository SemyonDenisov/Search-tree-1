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
		Print(root);
	}
	void Print(node* root) {
		if (root != NULL) 
		{
			cout << "Key - " << root->key << " String - " << root->value << endl;
			Print(root->left);
			Print(root->right); 
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
			Insert(key, value, root);
			return true;
		}
		else
			return false;
	}
	node* Insert(int key, string value,node*root)
	{
		if (root == NULL) {
			root = new node;
			root->left = NULL;
			root->right = NULL;
			root->key = key;
			root->value = value;
		}
		else if (key < root->key)
			root->left = Insert(key, value,root->left);
		else 
			root->right = Insert(key, value, root->right);
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
	bool erase(int key)
	{
		return Erase(root, key);
	}
	node* Erase(node* root, int key) {
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
};
int main()
{
	Map A;
	A.insert(1,"Senja");
	A.insert(2, "Pops");
	A.insert(-1, "hueps");
	A.insert(-2, "d");
	A.insert(6, "Styopakazel");
	A.insert(3, "check");
	A.insert(0, "check_1");
	A.erase(0);
	A.print();
	return 0;
}