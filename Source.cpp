#include "Set.h"
int main()
{
	Set s;
	s.insert(15);
	s.insert(30);
	s.insert(8);
	s.insert(4);
	s.insert(5);
	s.insert(10);
	s.insert(9);
	s.insert(11);
	s.print();
	cout << endl;
	s.erase(8);
	s.erase(15);
	s.erase(5);
	s.print();
	return 0;
}