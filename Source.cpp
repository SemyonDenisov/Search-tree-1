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
	A.erase(0);
	A.erase(2);
	A.print();
	return 0;
}