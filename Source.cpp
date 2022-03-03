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
	/*void print()
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
	}*/
	void print()
	{
		treeprint(root);
	}
	void treeprint(node* root) {
		if (root != NULL) { //Пока не встретится пустой узел
			cout << "Key - " << root->key << " String - " << root->value << endl; //Отображаем корень дерева
			treeprint(root->left); //Рекурсивная функция для левого поддерева
			treeprint(root->right); //Рекурсивная функция для правого поддерева
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
		else if (key < root->key)
			root->left = call_insert(key, value,root->left);
		else 
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
	A.insert(6, "Styopakazel");
	A.insert(3, "check");
	A.insert(0, "check_1");
	A.print();
	return 0;
}