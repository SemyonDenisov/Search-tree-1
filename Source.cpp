#include "map.h"
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
	string res = A.find(1);
	A.erase(1);
	A.erase(2);
	cout << res<< endl;
	A.print();
	bool ex = true;
	int n;
	while (ex)
	{
		std::cout << "Choise the menu item:" << std::endl;
		std::cout << "1)Print map" << std::endl;
		std::cout << "2)Insert element" << std::endl;
		std::cout << "3)Find element" << std::endl;
		std::cout << "4)Erase element" << std::endl;
		std::cout << "5)Exit" << std::endl;
		std::cin >> n;
		system("cls");
		switch (n)
		{

		case 1://
		{
			A.print();
			break;
		}

		case 2://
		{
			int key;
			string value;
			system("cls");
			std::cout << "Enter the key" << std::endl;
			std::cin >> key;
			std::cout << "Enter the string" << std::endl;
			std::cin >> value;
			if (A.insert(key,value))
			{
				system("cls");
				std::cout << "Success" << std::endl;
			}
			else
				std::cout << "Element with the same key alredy exist" << std::endl;
			break;
		}

		case 3://
		{
			int key;
			system("cls");
			std::cout << "Enter the key" << std::endl;
			std::cin >> key;
			string res = A.find(key);
			if (res != "/0")
			{
				std::cout << res << std::endl;
			}
			else
				std::cout << "Element with entered key are not exist" << std::endl;
			break;
		}

		case 4://
		{
			int key;
			system("cls");
			std::cout << "Enter the key" << std::endl;
			std::cin >> key;
			bool res = A.erase(key);
			if (res)
			{
				std::cout << "Success"<< std::endl;
			}
			else
				std::cout << "Element with entered key are not exist" << std::endl;
			break;
		}
		case 5://Exit
		{
			system("cls");
			ex = false;
		}
		}
	}
	return 0;
}