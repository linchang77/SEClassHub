// test iterator
#include <iostream>
#include <vector>
#include <list>

using namespace std;


int main()
{
	const int SIZE = 8;
	int ia[SIZE] = {8, 34, 3, 13, 1, 21, 5, 2};
	
	int *p = &ia[0];
	
	//test iterator	
	vector<int>::iterator it1;
	vector<int>::iterator it5;
	vector<int>::const_iterator it2;
	vector<string>::iterator it3;
	list<int>::iterator it4;
	
	it1 = it5;
//	it1 = p;
//	it1 = it2;
//	it1 = it3;
//	it1 = it4;
		
	return 0;
}





